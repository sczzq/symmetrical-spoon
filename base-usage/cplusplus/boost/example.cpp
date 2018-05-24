/*************************************************************************
	> File Name: example.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 05 May 2017 11:17:16 PM CST
 ************************************************************************/

#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	using namespace boost::lambda;
	typedef std::istream_iterator<int> in;

	std::for_each(
			in(std::cin), in(), std::cout << (_1 * 3) << " ");
	
}

