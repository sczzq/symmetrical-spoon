#include "cpp_header.h"

int main()
{
	map<int,int> mm;

	mm[1] = 1;
	mm[2] = 2;
	mm[3] = 3;
	mm[4] = 4;
	mm[5] = 5;

	for(auto m : mm)
	{
		cout << "1, " << m.first << ", " << m.second << "\n";
		for(auto m2 : mm)
		{
			cout << "----------------2, " << m2.first << ", " << m2.second << "\n";
		}
	}

	return 0;
}
