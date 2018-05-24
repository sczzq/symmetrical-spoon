/*************************************************************************
	> File Name: utils.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 11 May 2018 04:33:38 PM CST
 ************************************************************************/

#include <iostream>

namespace MyUtils {
	/*
	 * 计算两个非负整数p和q的最大公约数：
	 * 若 q 是 0 ，则最大公约数为 p .
	 * 否则，将 p 除以 q 得到余数 r，p 和 q 的最大公约数
	 *     即为 q 和 r 的最大公约数.
	 */
	int gcd(int p, int q)
	{
		if(q == 0) return p;
		int r = p % q;
		return gcd(q, r);
	}
};
