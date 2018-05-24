/*************************************************************************
	> File Name: pex59.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 24 Apr 2017 01:13:18 PM CST
 ************************************************************************/

#include<fstream>
using namespace std;

int main()
{
	ofstream ofs("test.txt", ofstream::out);

	for(int i = 0; i < 150; i++)
		ofs << i;
	ofs.close();

	return 0;
}
