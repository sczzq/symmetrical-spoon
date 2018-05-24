/*************************************************************************
	> File Name: dc.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 15 Apr 2018 04:55:39 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

enum class Kind : char {
	name, number, end,
	plus='+',minus='-',mul='*',div='/',print=';',assign='=',lp='(',rp=')'
};

struct Token{
	Kind kind;
	string string_value;
	double number_value;
};

class Token_stream{
	public:
		Token_stream(istream& s) : ip {&s}, owns{false} { }
		Token_stream(istream* p) : ip{p}, owns{true} { }
		~Token_stream() { close(); }

		Token get();
		Token& current(){ return ct; }

		void set_input(istream& s) { close(); ip = &s; owns = false;}
		void set_input(istream* p) {close(); ip = p; owns = true;}

		double error(const string & s)
		{
			no_of_errors++;
			cerr << "error: " << s << "\n";
			return 1;
		}
	private:
		void close() { if(owns) delete ip;}

		istream* ip;
		bool owns;
		Token ct{Kind::end};
		int no_of_errors = 0;
};

Token Token_stream::get()
{
	char ch = 0;
	do {
		if(!ip->get(ch)) return ct={Kind::end};
	} while(ch!='\n' && isspace(ch));

//	*ip >> ch;

	switch(ch){
		case 0:
			return ct = {Kind::end};
		case ';':
		case '\n':
			return ct={Kind::print};
		case '*':
		case '/':
		case '+':
		case '-':
		case '(':
		case ')':
		case '=':
			return ct={static_cast<Kind>(ch)};
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case'9':
		case '.':
			ip->putback(ch);
			*ip>>ct.number_value;
			ct.kind = Kind::number;
			return ct;
		default:
			if(isalpha(ch)){
				ct.string_value = string{ch};
				while(ip->get(ch) && isalnum(ch)){
					ct.string_value += ch;
				}
				ip->putback(ch);
//				*ip>>ct.string_value;
				ct.kind = Kind::name;
				return ct;
			}
			error("bad token");
			return ct={Kind::print};
	}
}

class Calculate {
	public :
		Calculate() { }
		~Calculate() { }

		double expr(bool );
		double prim(bool );
		double term(bool );

		int start();

		double error(const string & s)
		{
			no_of_errors++;
			cerr << "error: " << s << "\n";
			return 1;
		}

	private:
		Token_stream ts {cin};
		map<string, double> table {{"pi", 3.14159265358979322385}, {"e", 2.7182818284590452354}};
		int no_of_errors = 0;
};

double Calculate::expr(bool get)
{
	double left = term(get);
	for(;;){
		switch(ts.current().kind){
			case Kind::plus:
				left += term(true);
				break;
			case Kind::minus:
				left += term(true);
				break;
			default:
				return left;
		}
	}
}

double Calculate::term(bool get)
{
	double left = prim(get);
	for(;;){
		switch(ts.current().kind){
			case Kind::mul:
				left *= prim(true);
				break;
			case Kind::div:
				if(auto d = prim(true)){
					left /= d;
					break;
				}
				return error("divide by 0");
			default:
				return left;
		}
	}
}

double Calculate::prim(bool get)
{
	if(get) ts.get();
	switch(ts.current().kind){
		case Kind::number:
			{
				double v = ts.current().number_value;
				ts.get();
				return v;
			}
		case Kind::name:
			{
				double& v = table[ts.current().string_value];
				if(ts.get().kind==Kind::assign){
					v = expr(true);
					table[ts.current().string_value] = v;
				}
				return v;
			}
		case Kind::minus:
			return -prim(true);
		case Kind::lp:
			{
				auto e = expr(true);
				if(ts.current().kind != Kind::rp) return error("')'expected");
				ts.get();
				return e;
			}
		default:
			return error("primary expected");
	}
}
int Calculate::start()
{
	for(;;){
		ts.get();
		if(ts.current().kind == Kind::end) break;
		if(ts.current().kind == Kind::print) continue;
		cout << expr(false) << '\n';
	}
}

int main()
{
	Calculate cal;

	return cal.start();
}
