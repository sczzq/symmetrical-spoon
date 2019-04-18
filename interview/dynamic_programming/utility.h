#ifndef _UTILITY_H_
#define _UTILITY_H_

#define START_TIME  struct timeval st, et; \
	gettimeofday(&st, NULL);

#define END_TIME gettimeofday(&et, NULL); \
	printf("elapsed time: %d second %d usecond\n",  \
			et.tv_usec >= st.tv_usec ? et.tv_sec - st.tv_sec : et.tv_sec - st.tv_sec - 1, \
			et.tv_usec >= st.tv_usec ? et.tv_usec - st.tv_usec : et.tv_usec - st.tv_usec + 1000000);

#include <vector>
int random_vector(std::vector<int> &vi, int min, int max, int size);

#endif

