/*************************************************************************
	> File Name: finally.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sat 07 Apr 2018 09:45:34 PM CST
 ************************************************************************/

#include <iostream>
#include <stdexcept>
#include <exception>
#include <cstdlib>

template<typename F>
struct Final_action {
	Final_action(F f): clean{f} {}
	~Final_action() { clean(); }
	F clean;
};

template<typename F>
Final_action<F> finally(F f)
{
	return Final_action<F>(f);
}

void test()
{
	int *p = new int{7};
	int *buf = (int *)malloc(100*sizeof(int));

	auto act1 = finally([&]{ delete p;
							 free(buf);
							 std::cout << "Goodbey, Cruel world.\n";
						   }
					   );

	int var = 0;
	std::cout << "var = " << var << "\n";

	{
		var = 1;
		auto act2 = finally([&]{
								std::cout << "finally\n";
								var = 7;
							   }
						   );
		std::cout << "var = " << var << "\n";
	}
	std::cout << "var = " << var << "\n";
}

int main()
try
{
	test();
}
catch(const std::range_error& )
{
	std::cerr << "range error: Not again\n";
}
catch(const std::bad_alloc&)
{
	std::cerr << "new ran out of memory\n";
}
catch(...)
{
	std::cerr << "something error\n";
}
