/*************************************************************************
	> File Name: 50_powx_n.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 03 May 2017 05:15:38 PM CST
 ************************************************************************/

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
	double myPow(double x, int n){
		double xx = x, res = 1;
		int nn = n;
		if( n == INT_MIN ) {
			n = -(n + 1);
		}
		if( n < 0 )	n = -n;
		while(n>0){
			double td = x;
			unsigned int i = 2;
			for(; i<n; i*=2)
				td *= td;
			n = n - i/2;
			cout << hex << n << endl;
			res *= td;
		}
		if( nn == INT_MIN ) res *= x; 
		if( nn < 0)	res = 1 / res;
		return res;
	}
};

int main()
{
	cout << "sizeof(double) = " << sizeof(double) << "\n";
	cout << "sizeof(long double) = " << sizeof(long double) << "\n";

	Solution s;
	double x = 2;
	for(int i=0; i<10; i++){
		cout << "s.myPow(" << x << "," << i << ")=" << s.myPow(x, i) << "\n";
//		x *= 2;
	}

	int i;
	x = 8.88023;
	i = 3;
	cout << "s.myPow(" << x << "," << i << ")=" << s.myPow(x, i) << "\n";

	x = 8.88023;
	i = -3;
	cout << "s.myPow(" << x << "," << i << ")=" << s.myPow(x, i) << "\n";
	x = 0.00001;
	i = 2147483647;
	cout << hex << i << endl;
	cout << "s.myPow(" << x << "," << i << ")=" << s.myPow(x, i) << "\n";
	x = 2.00;
	i = -2147483648;
	cout << hex << i << endl;
	cout << "s.myPow(" << x << "," << i << ")=" << s.myPow(x, i) << "\n";
}

