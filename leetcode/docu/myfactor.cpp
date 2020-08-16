#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int input = -1;
	if (argc == 2)
	{
		input = atol(argv[1]);
	}
	else
	{
		cout << "input digits\n";
		return 0;
	}

	int cur = 2;
	cout << input << ": ";
	while(cur < input)
	{
		int div = input / cur;
		int mod = input % cur;
		if (mod == 0)
		{
			input = div;
			cout << cur << " ";
		}
		else
			cur++;
	}
	if (input == 1 || cur == input)
	{
		cout << input << "\n";
	}

	return 0;
}

