/*************************************************************************
	> File Name: getrusage.h
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 06 Jun 2017 07:43:59 PM CST
 ************************************************************************/

#ifndef GETRUSAGE_H_M_H
#define GETRUSAGE_H_M_H


#define SHOW_TIMEVAL(tv) \
	do { \
		printf("time: %d seconds, %d milliseconds\n", tv.tv_sec, tv.tv_usec); \
	} while(0);

int show_rusage(struct rusage *rusage)
{
	// struct timeval ru_utime
	printf("Time spent executing user instructions: ");
	SHOW_TIMEVAL(rusage->ru_utime);
	// struct timeval ru_stime
	printf("Time spent in operating system code on behalf of processes: ");
	SHOW_TIMEVAL(rusage->ru_stime);
	// long int ru_maxrss
	printf("The maximum resident set size used, in kilobytes, this is the maximum number of kilobytes of physical memory that processes used simultaneously, %ld\n", rusage->ru_maxrss);
	// long int ru_ixrss
	printf("An integral value expressed in kilobytes times ticks of execution, which indicates the amount of memory used by text that was shared with other processes, %ld\n", rusage->ru_ixrss);
	// long int ru_idrss
	printf("An integeral value expressed the same way, which is the amount of unshared memory used for data, %ld\n", rusage->ru_idrss);
	// long int ru_isrss
	printf("An integeral value expressed the same way, which is the amount of unshared memory used for stack space, %d\n", rusage->ru_isrss);
	// long int ru_minflt
	printf("The number of page faults which were serviced without requiring any I/O, %ld\n", rusage->ru_minflt);
	// long int majflt
	printf("The number of page faults which were serviced by doing I/O, %ld\n", rusage->ru_majflt);
	// long int ru_nswap
	printf("The number of times processes was swaped entirely out of main memory, %ld\n", rusage->ru_nswap);
	// long int ru_inblock
	printf("The number of times the file system had to read from the disk on behalf of processes, %ld\n", rusage->ru_inblock);
	// long int ru_oublock
	printf("The number of times the file system had to write to the disk on behalf of processes, %ld\n", rusage->ru_oublock);
	// long int ru_msgsnd
	printf("Number of IPC messages sent, %ld\n", rusage->ru_msgsnd);
	// long int ru_msgrcv
	printf("Number of IPC messages received, %ld\n", rusage->ru_msgrcv);
	// long int ru_nsignals
	printf("Number of signals received, %ld\n", rusage->ru_nsignals);
	// long int ru_nvcsw
	printf("The number of times processes voluntarily invoked a context switch(usually to wait for some service), %ld\n", rusage->ru_nvcsw);
	// long int ru_nivcw
	printf("The number of times an involuntary context switch took place (because a time slice expired, or another process of higher priority was scheduled), %ld\n", rusage->ru_nivcsw);
}

int show_rusagehead(void)
{
	printf("utime   stime    maxrss  ixrss  idrss  isrss  minflt  majflt  nswap  inblock  oublock  msgsnd  msgrcv  nsignals  nvcsw  nivcsw\n");
}

int show_rusage2(struct rusage* ru)
{
	printf("%ld.%ld\t", ru->ru_utime.tv_sec, ru->ru_utime.tv_usec);
	printf("%ld.%ld\t", ru->ru_stime.tv_sec, ru->ru_stime.tv_usec);
	printf("%-5ld\t", ru->ru_maxrss);
	printf("%-5ld\t", ru->ru_ixrss);
	printf("%-5ld\t", ru->ru_idrss);
	printf("%-5ld\t", ru->ru_isrss);
	printf("%-5ld\t", ru->ru_minflt);
	printf("%-5ld\t", ru->ru_majflt);
	printf("%-5ld\t", ru->ru_nswap);
	printf("%-5ld\t", ru->ru_inblock);
	printf("%-5ld\t", ru->ru_oublock);
	printf("%-5ld\t", ru->ru_msgsnd);
	printf("%-5ld\t", ru->ru_msgrcv);
	printf("%-5ld\t", ru->ru_nsignals);
	printf("%-5ld\t", ru->ru_nvcsw);
	printf("%-5ld\n", ru->ru_nivcsw);
}


#endif // endof file
