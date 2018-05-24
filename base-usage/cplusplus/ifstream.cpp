/*************************************************************************
	> File Name: ifstream.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 06 Apr 2018 11:15:31 AM CST
 ************************************************************************/

#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include <array>

int main(int argc, char *argv[])
{
	assert(argc > 1);

	std::string infile {argv[1]};
	std::ifstream in {infile};

	std::string tos;

	while(!in.eof()){
		in >> tos;
		std::cout << tos << std::endl;
	}

	/*
	std::array<char, 1024> content;
	try{
		while(!in.eof()){
			in.read(content.data(), content.size());
			std::cout << std::string(content.data()) << std::endl;
		}
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	*/
	in.close();

	return 0;
}
