/*************************************************************************
	> File Name: test_using.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月14日 星期一 21时03分19秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

using std::vector;

int main()
{
	vector<int> vi {1, 2, 3};

	for(auto i : vi)
		std::cout << i << " ";
	std::cout << "\n";
}
