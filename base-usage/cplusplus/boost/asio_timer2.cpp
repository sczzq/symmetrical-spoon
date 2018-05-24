/*************************************************************************
	> File Name: asio_timer2.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 22 May 2017 06:00:17 PM CST
 ************************************************************************/

#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void print(const boost::system::error_code& )
{
	std::cout << "hello world" << std::endl;
}

int main()
{
	boost::asio::io_service io;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));

	t.async_wait(&print);

	io.run();

	std::cout << "after async wait" << std::endl;

	return 0;
}
