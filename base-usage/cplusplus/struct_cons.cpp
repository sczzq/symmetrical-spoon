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

struct ooops : std::exception {
	const char *err;
	ooops(const char *msg) : err{msg} 
		{ }
	const char *what() const noexcept { return err; }
};

using std::string;

struct Address {
	string name;
	int number;
	string street;
	string town;
	string state;
	string zip;

	Address() { };
	Address(const string n, int nu, const string &s, const string &t, const string& st, int z);
};

Address::Address(const string n, int nu, const string &s, const string &t, const string& st, int z)
	:name{n},
	number{nu},
	street{s},
	town{t},
	state{st}
{
	if((st.length() != 2))
		throw ooops{"state size isnot 2\n"};
	std::ostringstream ost;
	ost << z;
	zip = ost.str();
	if(zip.length() != 4 && zip.length() != 5)
		throw ooops{"zip size isnot 4 or 5\n"};
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
	"NJ",
	7890
};

void print_addr(Address *p)
{
	std::cout << p->name << '\n'
		<< p->number << ' ' << p->state << '\n'
		<< p->town << '\n'
		<< p->state << ' ' 
		<< p->zip << '\n';
}

void print_addr2(const Address &r)
{
	std::cout << r.name << '\n'
		<< r.number << ' ' << r.street << '\n'
		<< r.town << '\n'
		<< r.state << ' '
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
	try{
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

		std::cout << "fifth\n";
		Address jd {"Jim Dnady", 61,
					"South St",
					"New Provider",
					"NJ",
					18900};
		print_addr2(jd);

		std::cout << "fifth\n";
		Address jd2 {"Jim Dnady", 61001,
					"South St",
					"New Provider",
					"NJA",
					1890000};
		print_addr2(jd2);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

}
