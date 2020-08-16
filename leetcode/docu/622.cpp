#include <iostream>

using namespace std;

int main()
{
	int a[10];

	for(int i = 0; i < 10; i++)
	{
		a[i] = i;
	}

	for(int i = 0; i < 10; i++)
	{
		cout << a[i] << "\n";
	}

	int *b;
	b = new int(10);

	for(int i = 0; i < 10; i++)
	{
		b[i] = i;
	}

	for(int i = 0; i < 10; i++)
	{
		cout << b[i] << "\n";
	}


}

