/*************************************************************************
	> File Name: number.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 23 Jan 2018 08:48:46 PM CST
 ************************************************************************/

int greatest_common_divisor(int a, int b)
{
	if (!a || !b)
		return a + b;
	if(a < b)
		greatest_common_divisor(b, a);
	int r = a - (a/b)*b;
	while(r){
		a = b;
		b = r;
		r = a - (a/b)*b;
	}
	return b;
}

inline integer_power(int r, int d)
{
	int dd = d;
	while(--r)
		d *= dd;
	return d;
}

inline double_power(int r, double d)
{
	double dd = d;
	while(--r)
		d *= dd;
	return d;
}

double root_approximation(int r, int d, int decision)
{
	double dr = r, dd = d;
	int magnitude = 1;
	double low = magnitude, high = d;
	int i = 0;
	double least_number = 1;
	while(i++<decision){
		least_number /= 10;
	}
	printf("least number %lf\n", least_number);
	while(magnitude > least_number && magnitude < dd){
		if(double_power(r, low) < dd)
	}
}

