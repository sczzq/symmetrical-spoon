/*************************************************************************
	> File Name: 69_sqrtx.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 03 May 2017 05:00:55 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution{
public:
	int mySqrt(int x){
		long long a = 0;
		long long xx = x;
		if(x < 0)
			return -1;
		while((a+1)*(a+1) <= x){
			a += 1;
		}
		return a;
	}
};

int main()
{
	Solution s;
	for(int i=0; i<10; i++)
		cout << i << ": " << s.mySqrt(i) << "\n";

	int i = 2147395600;
	cout << i << ": " << s.mySqrt(i) << "\n";

}
