/*************************************************************************
	> File Name: pex56.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 24 Apr 2017 12:33:21 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class stu{
	string name;
	int age;
public:
	stu(string s = {}, int a=0): name(s), age(a){ };
	friend ostream& operator<<(ostream& out, stu& A);
	friend istream& operator>>(istream& in, stu& A);
/*
	ostream& operator<<(ostream& out)
	{
		out << "name: " << name << ", age: " << age;
		return out;
	}

	istream& operator>>(istream& in)
	{
		in >> name >> age;
		return in;
	}
*/
};

ostream& operator<<(ostream& out, stu& A)
{
	out << "name: " << A.name << ", age: " << A.age;
	return out;
}

istream& operator>>(istream& in, stu& A)
{
	in >> A.name >> A.age;
	return in;
}

int main()
{
	stu s;
	cin >> s;
	cout << s << endl;
}

