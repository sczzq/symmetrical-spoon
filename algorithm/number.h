/*************************************************************************
	> File Name: number.h
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 23 Jan 2018 09:09:33 PM CST
 ************************************************************************/

#ifndef _NUMBER_H
#define _NUMBER_H

#ifdef _cplusplus
extern 'C'{
#endif

/*
 * find greatest common divisor of a and b
 * if a is 0 or b is 0, then get a+b
 * Euclidean algorithm
 * being a = q*b + r,
 * then (a, b) = (b, r)
 * continue till to r is zero, ie, (q1, r1) = (r1, 0)
 * then gcd is r1
 *
 */
int greatest_common_divisor(int a, int b);


#ifdef _cplusplus
}
#endif

#endif

