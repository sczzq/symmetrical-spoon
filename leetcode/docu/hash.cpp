#include "cpp_header.h"

int main()
{
	string s = "hello world";
	hash<string> hash_fn;


	s = "Stand back? I'v got jimmies";

	size_t hh = hash_fn(s);

	cout << hh << "\n";
}



