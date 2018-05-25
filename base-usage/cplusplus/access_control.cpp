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
		int getSeqNo(){ return ++seqNo; }
	protected:
		int getTotalNo() { return ++totalNo; }
	public:
		int getCurNo() { return ++curNo; }
};

// derived class can access to the protected member of base class.
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

	// at this context,
	// the privated member in class B cannot be accessed.
//	std::cout << x.getSeqNo() << std::endl;
	// at this context,
	// the protected member in class B cannot be accessed.
//	std::cout << x.getTotalNo() << std::endl;
	std::cout << x.getCurNo() << std::endl;

	std::cout << x.getBSeqNo() << std::endl;
	std::cout << y.getBSeqNo() << std::endl;
	std::cout << z.getBSeqNo() << std::endl;

	std::cout << x.getBTotalNo() << std::endl;
	// at this context,
	// the protected member in class Y cannot be accessed.
//	std::cout << y.getBTotalNo() << std::endl;
	std::cout << z.getBTotalNo() << std::endl;

	std::cout << x.getBCurNo() << std::endl;
	// at this context,
	// the protected member in class Y cannot be accessed.
//	std::cout << y.getBCurNo() << std::endl;
	std::cout << z.getBCurNo() << std::endl;

}


