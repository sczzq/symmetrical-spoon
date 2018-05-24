/*************************************************************************
	> File Name: boost_example1.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 24 Apr 2017 06:12:32 PM CST
 ************************************************************************/

#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	using namespace boost::lambda;
	typedef std::istream_iterator<int> in;

	std::for_each(
			in(std::cin), in(), std::cout << (_1 * 3) << " " );
}
