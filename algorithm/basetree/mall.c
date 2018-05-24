/* mall.c -- use Queue interface */
/* compile with queue.c */
#include <stdio.h>
#include <stdlib.h> /* prototype of rand(0 and srand() functions */
#include <time.h> /* prototype of time() function */
#include "queue.h"
#define MIN_PER_HR 60.0

bool newcustomer(double x);  /* is new customer coming? */
Item customertime(long when); /* set customer parameter */

int main(void)
{
	Queue line;
	Item temp;  /* about new customer data */
	int hours;  /* simulate hours */
	int perhour; /* customer number per hour */
	long cycle, cyclelimit; /* cycle times, times limit */
	long turnaways = 0; /* refused customers number caused by queue is full */
	long customers = 0; /* customers added to queue */
	long served = 0; /* customers be served in simulate hours */
	long sum_line = 0; /* accumulated queue length */
	int wait_time = 0; /* time from current to empty */
	double min_per_cust; /* average time that each customer coming */
	long line_wait = 0; /* accumulated queue waiting time */

	InitializeQueue(&line);
	srand(time(0));
	puts("Case Study: Sigmund Lander's Advice Booth");
	puts("Enter the number of simulation hours: ");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Enter the average number of customers per hour: ");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;

	for(cycle = 0; cycle < cyclelimit; cycle++)
	{
		if(newcustomer(min_per_cust))
		{
			if(QueueIsFull(&line))
				turnaways++;
			else
			{
				customers++;
				temp = customertime(cycle);
				EnQueue(temp, &line);
			}
		}
		if(wait_time <= 0 && !QueueIsEmpty(&line))
		{
			DeQueue(&temp, &line);
			wait_time = temp.processtime;
			line_wait += cycle - temp.arrive;
			served++;
		}
		if(wait_time > 0)
			wait_time--;
		sum_line += QueueItemCount(&line);
	}
	if(customers > 0)
	{
		printf("customer accepted: %ld\n", customers);
		printf(" customes served: %ld\n", served);
		printf("   turnaways: %ld\n", turnaways);
		printf("average queue size: %.2f\n", (double)sum_line/cyclelimit);
		printf("  average wait time: %.2f minutes\n", (double)line_wait/served);
	}
	else
		puts("No customers!");
	EmptyTheQueue(&line);
	puts("Bye!");

	return 0;
}

bool newcustomer(double x)
{
	if(rand()*x / RAND_MAX < 1)
		return true;
	else
		return false;
}

Item customertime(long when)
{
	Item cust;

	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}

