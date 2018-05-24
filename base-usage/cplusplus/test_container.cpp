/*************************************************************************
	> File Name: test_container.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Thu 27 Apr 2017 08:52:52 PM CST
 ************************************************************************/

#include <iostream>
#include <vector> // vector
#include <list> // list 
#include <map> // map
#include <unordered_map> // unordered_map
#include <string> // string
#include <algorithm> // count_if
using namespace std;

struct Entry{
	string name;
	int number;
};

ostream& operator<<(ostream& os, const Entry& e)
{
	return os << "{\"" << e.name << "\"," << e.number << "}";
}

istream& operator>>(istream& is, Entry& e)
{
	char c, c2;
	if(is>>c && c=='{' && is>>c2 && c2=='"'){
		string name;
		while(is.get(c) && c!='"')
			name+=c;
		if(is>>c && c==','){
			int number = 0;
			if(is>>number>>c && c=='}'){
				e = {name, number};
				return is;
			}
		}
	}
//	is.setf(ios_base::failbit);
	return is;
}

int foo(){
	for(Entry ee ; cin>>ee; )
		cout << ee << "\n";
}

int g()
{
	string s{"hello world"};
	s.replace(0,5,"the plain of the");
	s+='\n';
	cout << s;
}

string m2(const string& s1, const string& s2)
{
	return s1 + '@' + s2;
}

void m3()
{
	auto address = m2("dmr", "bell-labs.com\n");
	cout << address;
}

void m4()
{
	for(int i=0; i<100000; i++){
		m3();
	}
}

void h1()
{
	cout << "Please enter some word\n";
	string str;
	cin >> str;
	cout << "Your enter is " << str << "\n";
}

void h2()
{
	cout << "Please enter some word\n";
	string str;
	getline(cin, str);
	cout << "Your enter is " << str << "\n";
}

template<typename T>
void print(T& t)
{
	for(const auto& x : t)
		cout << x << ';';
	cout << endl;
}

template<typename T>
int get_number(T& t, const string& s)
{
	for(const auto& x : t)
		if(x.name == s)
			return x.number;
	return 0;
}

void c1()
{
	vector<Entry> phone_book = {
		{"David Hume", 12346},
		{"Karl Popper", 234567},
		{"Bertrand Arthur William Russell", 345678}
	};

	print(phone_book);
	cout << get_number(phone_book, "David Hume") << '\n';
}

void c2()
{
	vector<int> vii;
	vector<int> vi(20);
	vector<string> vs(30);
	vector<double> vd(20, 23.99);

	print(vii);
	print(vi);
	print(vs);
	print(vd);
}

void c3()
{
	list<Entry> phone_book = {
		{"David Hume", 123456},
		{"Karl Popper", 234567},
		{"Bertrand Arthur William Russell", 345678}
	};

	print(phone_book);
	cout << get_number(phone_book, "David Hume") << '\n';
}

template<typename T>
int get_map_number(T& m, const string& str)
{
	return m[str];
}

void c4()
{
	map<string, int> phone_book = {
		{"David Hume", 123456},
		{"Karl Popper", 234567},
		{"Bertrand Arthur William Russell", 345678}
	};

//	print(phone_book);
	cout << get_map_number(phone_book, "David Hume") << '\n';
}

void c5()
{
	unordered_map<string, int> phone_book = {
		{"David Hume", 123456},
		{"Karl Popper", 234567},
		{"Bertrand Arthur William Russell", 345678}
	};
	cout << get_map_number(phone_book, "David Hume") << '\n';
}

// template aliase unsupported, g++ 3.8.5, -std=c++11
//template <typename T>
//using Iterator<T> = typename T::iterator;

template <typename T>
class Greater_than{
	const T val;
public:
	Greater_than(T v):val{v} { }
	bool operator()(T& v){ return v > val; }
};

template<typename C, typename V>
vector<typename C::iterator> find_all(C& c, V v)
{
	vector<typename C::iterator> vp;
	for(auto p=c.begin(); p!=c.end(); ++p)
		if(*p == v)
			vp.push_back(p);
	return vp;
}

void iter1()
{
	string s{"hello world, this is plain world"};
	char c = 'l';
	for(auto& p : find_all(s,c))
		if(*p != c)
			cout << "a bug\n";
		else
			cout << *p << "\n";
	cout << endl;
}

void algo1()
{
	vector<int> vi {3,4,5,6,4,5,6,5};
	print(vi);
	cout << "greater than 3 count is " << count_if(vi.begin(), vi.end(), Greater_than<int>{3}) << '\n';
	auto x = find(vi.begin(), vi.end(), 4);
	cout << "first equal 4 is " << *x << '\n';
	x = find_if(vi.begin(), vi.end(), Greater_than<int>{4});
	cout << "first greater than 4 is " << *x << '\n';
}

int main()
{
//	foo();
//	g();
//	m4();
//	h1();
//	h2();
//	c1();
//	c2();
//	c3();
//	c4();
//	c5();
//	iter1();
	algo1();
}


