/*************************************************************************
	> File Name: asio_timer3.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 22 May 2017 06:05:14 PM CST
 ************************************************************************/

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void print(const boost::system::error_code& ,
		boost::asio::deadline_timer* t, int* count)
{
	std::cout << "A" << std::endl;
	if(*count < 5){
		std::cout << *count << std::endl;
		++(*count);
		std::cout << "a" << std::endl;
		t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
		std::cout << "b" << std::endl;
		t->async_wait(boost::bind(print,
					boost::asio::placeholders::error, t, count));
		std::cout << "c" << std::endl;
	}
	std::cout << "d" << std::endl;
}

int main()
{
	boost::asio::io_service io;
	int count = 0;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(1));

	t.async_wait(boost::bind(print,
				boost::asio::placeholders::error, &t, &count));

	io.run();

	std::cout << "Final count is " << count << std::endl;

	return 0;
}

