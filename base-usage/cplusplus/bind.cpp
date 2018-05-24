/*************************************************************************
	> File Name: bind.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 26 May 2017 10:40:38 PM CST
 ************************************************************************/

#include <iostream> // std::cout
#include <functional> // std::bind

using namespace std;

double my_divide(double x, double y) { return x/y; }

struct MyPair {
	double a, b;
	double multiply() { return a*b; }
};

int main() {
	using namespace std::placeholders;

	auto fn_five = std::bind (my_divide, 10, 2);
	std::cout << fn_five() << '\n';

	auto fn_half = std::bind (my_divide, _1, 2);
	std::cout << fn_half(10) << '\n';

	auto fn_invert = std::bind(my_divide, _2, _1);
	std::cout << fn_invert(10, 2) << '\n';

	auto fn_rounding = std::bind<int>(my_divide, _1, _2);
	std::cout << fn_rounding(10, 3) << '\n';

	MyPair ten_two {10, 2};

	auto bound_member_fn = std::bind(&MyPair::multiply, _1);
	std::cout << bound_member_fn(ten_two) << '\n';

	auto bound_member_data = std::bind(&MyPair::a, ten_two);
	std::cout << bound_member_data() << '\n';

	return 0;
}

