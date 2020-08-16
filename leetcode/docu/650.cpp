#include <iostream>
#include <map>
#include <climits>

using namespace std;

class Solution {
public:
	int minSteps(int n){
		if(n == 1) return 0;
		if( 2 <= n && n <= 4) return n;

		int min = INT_MAX;
		int is_split = 0;
		for(int i = 2; i * 2 <= n; i++)
		{
			if(n % i == 0)
			{
				int cur = minSteps(i) + minSteps(n/i);
				if(cur < min)
				{
					min = cur;
				}
				is_split = 1;
			}
		}

		if(is_split == 0)
		{
			return n;
		}

		return min;
	}
};

int main()
{
	Solution s;

	cout << "1 : " << s.minSteps(1) << "\n";
	cout << "2 : " << s.minSteps(2) << "\n";
	cout << "3 : " << s.minSteps(3) << "\n";
	cout << "4 : " << s.minSteps(4) << "\n";
	cout << "5 : " << s.minSteps(5) << "\n";
	cout << "6 : " << s.minSteps(6) << "\n";
	cout << "7 : " << s.minSteps(7) << "\n";
	cout << "8 : " << s.minSteps(8) << "\n";
	cout << "9 : " << s.minSteps(9) << "\n";
	cout << "10 : " << s.minSteps(10) << "\n";
	cout << "11 : " << s.minSteps(11) << "\n";
	cout << "12 : " << s.minSteps(12) << "\n";
	cout << "13 : " << s.minSteps(13) << "\n";
	cout << "14 : " << s.minSteps(14) << "\n";
	cout << "15 : " << s.minSteps(15) << "\n";
	cout << "16 : " << s.minSteps(16) << "\n";
}
