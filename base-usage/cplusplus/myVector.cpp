/*************************************************************************
	> File Name: myVector.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Thu 27 Apr 2017 04:59:46 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

template<typename T>
class Vec : public std::vector<T>{
public:
	using std::vector<T>::vector;

	T& operator[](unsigned int i){
		return vector<T>::at(i);
	}

	T& operator[](unsigned int i) const {
		return vector<T>::at(i);
	}

};

int main()
{
	try{
		vector<string> strs {"hello", "world"};
		cout << strs.at(2) << endl;
	} catch(const std::out_of_range& oor){
		cout << "range error" << oor.what() << endl;
	}
}
