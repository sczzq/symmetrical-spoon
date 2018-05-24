/*************************************************************************
	> File Name: test_allocator.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 23 May 2017 12:39:53 PM CST
 ************************************************************************/

#include <memery>
#include <iostream>
#include <string>

int main()
{
	std::allocator<int> a1;
	int* a = a1.allocator(10);

	a[9] = 7;

	std::cout << a[9] << '\n';

	a1.deallocator(a, 10);

	std::allocator<std::string> a2;

	decltype(a1)::rebind<std::string>::other a2_1;

	std::allocator_traits<decltype(a1)>::rebind_alloc<std::string> a2_2;

	std::string* s= a2.allocate(2);

	a2.construct(s, "f00");
	a2.construct(s + 1, "bar");

	std::cout << s[0] << ' ' << s[1] << '\n';

	a2.destroy(2);
	a2.destroy(s + 1);
	a2.deallocate(s, 2);
}

