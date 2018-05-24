/*************************************************************************
	> File Name: function_template.h
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月14日 星期一 20时33分20秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <exception>

namespace sczzq{

template<typename Container, typename Value>
Value sum(const Container& c, Value v)
{
	for(int i = 0; i < c.size(); ++i)
		v += c[i];
	return v;
}

template<typename T>
class Less_than{
	private:
		const T val;
	public:
		Less_than(const T& v) : val(v) {}
		bool operator()(const T& x) const { return x < val; }
};

template< typename C, typename P>
int count(const C& c, P pred)
{
	int cnt = 0;
	for(const auto& x : c)
		if(pred(x))
			++cnt;
	return cnt;
}

template<typename C, typename Oper>
void for_all(C& c, Oper op)
{
	for(auto& x : c)
		op(*x);
}

};

using namespace sczzq;

using std::unique_ptr;
using std::vector;

unique_ptr<vector<int>>
read_int(std::istream& is)
{
	unique_ptr<vector<int>> vi = unique_ptr<vector<int>>(new vector<int>(0));
	int i;
	while(is.good()){
		is >> i;
		vi->push_back(i);
	}
	std::cout << "read_int\n";
	return vi;
}

void user()
{
	using std::cin;
	vector<unique_ptr<vector<int>>> v;
	while(cin)
		v.push_back(read_int(cin));
	for_all(v,[](vector<int> & s){std::cout << s.size() << std::endl; });
}

int main()
try{
	unique_ptr<vector<int>> teevi (new vector<int>);
	unique_ptr<vector<int>> teevi2 (new vector<int>(10));
	unique_ptr<vector<int>> teevi3 (new vector<int>(-10));
	using string = std::string;

	Less_than<int> lti{42};
	Less_than<string> lts{"Backups"};

	bool b1 = lti(20); // if 20 < 42 is true, else is false.
	bool b2 = lti(42); // if 42 < 42 is true, else is false.

	bool b3 = lts("hello"); // if "hello" < "Backups" is true, else is false.

	std::cout << b1 << ", " << b2 << ", " << b3 << "\n";

	vector<int> vi{1,2,310, 202, 2201, 111};
	std::cout << count(vi, lti) << std::endl;

	user();
}
//catch(expection & e){ // 低级的拼写错误,导致不易追踪的错误,
			//明晓此种错误,将拼写错误作为检查之一.
catch(std::exception & e){
	std::cout << e.what() << std::endl;
}


