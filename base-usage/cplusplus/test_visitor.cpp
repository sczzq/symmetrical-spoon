/*************************************************************************
	> File Name: test_visitor.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 07 May 2017 07:27:48 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

class Visitor;

class Node{
public:
	virtual void accept(Visitor& ) = 0;
};

class Expr : public Node {
public:
	Expr(string str) : s{str} { }
	void accept(Visitor& ) override;
	const string& get() { return s; }
private:
	string s;
};

class Stmt : public Node {
public:
	Stmt(string str) : s{str} { }
	void accept(Visitor& ) override;
	const string& get() { return s; };
private:
	string s;
};

class Visitor{
public:
	virtual void accept(Expr&) = 0;
	virtual void accept(Stmt&) = 0;
};

class Do1_Visitor : public Visitor{
public:
	void accept(Expr& e) { cout << "do1 expr visitor, " << e.get() << endl; }
	void accept(Stmt& s) { cout << "do1 stmt visitor, " << s.get() << endl; }
};

class Do2_Visitor : public Visitor{
public:
	void accept(Expr& e) { cout << "do2 expr visitor," << e.get() << endl; }
	void accept(Stmt& s) { cout << "do2 stmt visitor," << s.get() << endl; }
};

void Expr::accept(Visitor& v) { v.accept(*this); }
void Stmt::accept(Visitor& v) { v.accept(*this); }

void test(Expr& e, Stmt& s, Visitor& do1, Visitor& do2)
{
	vector<pair<Node*, Visitor*>> vn{{&e, &do1}, {&e, &do2}, {&s, &do1}, {&s, &do2}};
	for(auto& p : vn){
		p.first->accept(*p.second);
	}
}

int foo()
{
	Do1_Visitor do1;
	Do2_Visitor do2;
	Expr e{"experence"};
	Stmt s{"statement"};
	test(e, s, do1, do2);
}

int main()
{
	foo();
}
