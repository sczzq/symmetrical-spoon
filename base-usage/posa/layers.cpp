/*************************************************************************
	> File Name: layers.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 03 Sep 2017 04:17:52 PM CST
 ************************************************************************/

#include <iostream>

class L1Provider {
public:
	virtual void L1Service() = 0;
};

class L2Provider {
	public:
		virtual void L2Service() = 0;
		void setLowerLayer(L1Provider *l1) { level1 = l1; }
	protected:
		L1Provider *level1;
};

class L3Provider {
	public:
		virtual void L3Service() = 0;
		void setLowerLayer(L2Provider *l2) { level2 = l2; }
	protected:
		L2Provider *level2;
};

class DataLink : public L1Provider {
	public:
		virtual void L1Service() {
			std::cout << "L1Service doing its job" << std::endl;
		};
};

class Transport : public L2Provider {
	public:
		virtual void L2Service(){
			std::cout << "L2Service starting its job" << std::endl;
			level1->L1Service();
			std::cout << "L2Service finishing its job" << std::endl;
		}
};

class Session : public L3Provider {
	public:
		virtual void L3Service(){
			std::cout << "L3Service starting its job" << std::endl;
			level2->L2Service();
			std::cout << "L3Service finishing its job" << std::endl;
		}
};

int main()
{
	DataLink dataLink;
	Transport transport;
	Session session;

	transport.setLowerLayer(&dataLink);
	session.setLowerLayer(&transport);

	session.L3Service();
}

