/*************************************************************************
	> File Name: struct.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 15 Apr 2018 10:41:01 AM CST
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <string>

#include <exception>

/*
 * define my exception class
 */
struct ooops : std::exception {
	const char *what() const noexpect { return "ooops\n" };
};

using std::string;

/*
 * define a struct.
 *
 */
struct Address {
	const char *name;
	int number;
	const char *street;
	const char *town;
	char state[2];
	const char *zip;

	Address(const string n, int nu, const string &s, const string &t, const string& st, int z);
};

Address::Address(const string n, int nu, const string &s, const string &t, const string& st, int z)
	:name{n},
	number{nu},
	street{s},
	town{t},
{
	if((st.size() != 2))
		throw ooops{};
	state = {st[0], st[1]};
	std::ostringstream ost;
	ost << z;
	string zi {ost.str()};
	switch(zi.size()){
	case 5:
		zip = {zi[0], zi[1], zi[2], zi[3], zi[4]};
		break;
	case 4:
		zip = {'0', zi[0], zi[1], zi[2], zi[3]};
		break;
	default:
		throw ooops;
	}
}

int f()
{
	Address jd;
	jd.name = "Jim Dandy";
	jd.number = 61;
}

Address jd = {
	"Jim Dandy",
	61, 
	"South St",
	"New Providence",
	{'N','J'},
	"07890"
};

void print_addr(Address *p)
{
	std::cout << p->name << '\n'
		<< p->number << ' ' << p->state << '\n'
		<< p->town << '\n'
		<< p->state[0] << p->state[1] << ' ' 
		<< p->zip << '\n';
}

void print_addr2(const Address &r)
{
	std::cout << r.name << '\n'
		<< r.number << ' ' << r.street << '\n'
		<< r.town << '\n'
		<< r.state[0] << r.state[1] << ' '
		<< r.zip << '\n';
}

Address current;
Address set_current(Address next)
{
	Address prev = current;
	current = next;
	return prev;
}

int main()
{
	f();
	std::cout << "first\n";
	print_addr(&jd);
	std::cout << std::endl;

	std::cout << "second\n";
	print_addr2(jd);
	std::cout << std::endl;

	std::cout << "third\n";
	print_addr2(set_current(jd));
	std::cout << std::endl;

	std::cout << "forth\n";
	print_addr2(current);
	std::cout << std::endl;

	Address jd {"Jim Dnady", 61,
				"South St",
				"New Provider",
				"NJ",
				18900};
	print_addr2(jd);
}
