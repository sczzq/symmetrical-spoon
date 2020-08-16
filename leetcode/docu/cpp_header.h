#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <climits>
#include <set>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <random>
#include <chrono>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <bitset>

using namespace std;

#define TESTCASE_p1(func, param, res, casenum)  \
	do {  \
		Solution sol; \
		if(sol.func(param) == res) \
		{ \
			cout << casenum << " pass\n"; \
		} \
		else \
		{ \
			cout << casenum << " no pass\n"; \
		} \
	}while(0)

#define TESTCASE_p2(func, param1, param2, res, casenum)  \
	do {  \
		Solution sol; \
		if(sol.func(param1, param2) == res) \
		{ \
			cout << casenum << " pass\n"; \
		} \
		else \
		{ \
			cout << casenum << " no pass\n"; \
		} \
	}while(0)


#define TESTCASE_p3(func, param1, param2, param3, res, casenum)  \
	do {  \
		Solution sol; \
		if(sol.func(param1, param2, param3) == res) \
		{ \
			cout << casenum << " pass\n"; \
		} \
		else \
		{ \
			cout << casenum << " no pass\n"; \
		} \
	}while(0)


#define TESTCASE_p4(func, param1, param2, param3, param4, res, casenum)  \
	do {  \
		Solution sol; \
		if(sol.func(param1, param2, param3, param4) == res) \
		{ \
			cout << casenum << " pass\n"; \
		} \
		else \
		{ \
			cout << casenum << " no pass\n"; \
		} \
	}while(0)



