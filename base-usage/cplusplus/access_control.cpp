/*************************************************************************
	> File Name: access_control.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 01 May 2018 10:30:57 AM CST
 ************************************************************************/

#include <iostream>

class B {
	protected:
		int seqNo = 0;
		int totalNo = 0;
	public:
		int curNo = 0;

	private:
		int getSeqNo(){ return seqNo++; }
	protected:
		int getTotalNo() { return totalNo++; }
	public:
		int getCurNo() { return curNo++; }
};

class X : public B {
	public:
		int getBSeqNo() { return seqNo; }
		int getBTotalNo() { return totalNo; };
		int getBCurNo() { return curNo; }
};

class Y : protected B { 
	public:
		int getBSeqNo() { return seqNo; }
	protected:
		int getBTotalNo() { return totalNo; };
		int getBCurNo() { return curNo; }
};

class Z : private B { 
	public:
		int getBSeqNo() { return seqNo; }
		int getBTotalNo() { return totalNo; };
		int getBCurNo() { return curNo; }
};

int main()
{
	X x;
	Y y;
	Z z;

	std::cout << x.getBSeqNo() << std::endl;
	std::cout << y.getBSeqNo() << std::endl;
	std::cout << z.getBSeqNo() << std::endl;

	std::cout << x.getBTotalNo() << std::endl;
	std::cout << y.getBTotalNo() << std::endl;
	std::cout << z.getBTotalNo() << std::endl;
}


