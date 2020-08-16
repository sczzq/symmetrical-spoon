#include <iostream>
#include <deque>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
private:
    std::deque<std::vector<int>> deq;
    int max = 0;
public:
	std::vector<int> res;
    int integerBreak(int n) {
        if(n == 2)
        {
            return 1;
        }
        if(n == 3)
        {
            return 2;
        }

        for(int i = 2; i <= n - i; i++)
        {
            std::vector<int> vi{i, n-i};
            deq.push_back(vi);
        }
        while(deq.size() > 0)
        {
			// check first element in deque
			check();

			// split first element in deque
			// push back new element if has.
            split2();

			// pop first element in deque
            deq.pop_front();
        }
        return max;
    }

	void check(void)
	{
		int temp = 1;
		std::vector<int> &vi = deq.at(0);
		for(int i = 0; i < vi.size(); i++)
		{
			temp *= vi[i];
		}

		if(max < temp)
		{
			max = temp;
			res = vi;
		}
	}

    void split2(void)
    {
		std::vector<int> &vi = deq.at(0);
		int from = vi[vi.size()-2];
		int n = vi[vi.size()-1];

		while(n - from >= from)
		{
			if (n - from - from < from) // cannot split, just check
			{
				int temp = 1;
				for(int i = 0; i < vi.size()-1; i++)
				{
					temp *= vi[i];
				}
				temp *= from;
				temp *= (n-from);
				if(max < temp)
				{
					max = temp;
					res = vi;
					res.erase(res.end()-1);
					res.push_back(from);
					res.push_back(n-from);
				}
			}
			else // should split again
			{
				std::vector<int> t = vi;
				t.erase(t.end() - 1);
				t.push_back(from);
				t.push_back(n - from);
				deq.push_back(t);
			}
			from++;
		}
    }
};

class Solution2 {
public:
	int integerBreak(int n)
	{
		vector<int> dp(n+1);
		for(int i = 2; i <= n; i++){
			int curMax = 0;
			for(int j = 1; j < i; j++) {
				curMax = max(curMax, max(j * (i - j), j * dp[i-j]));
			}
			dp[i] = curMax;
		}
		return dp[n];
	}
};

class Solution3 {
	public:
		int integerBreak(int n)
		{
			if(n < 4)
			{
				return n -1;
			}
			vector<int> dp(n+1);
			dp[2] = 1;
			for(int i = 3; i <= n; i++)
			{
				dp[i] = max(max(2*(i-2), 2*dp[i-2]), max(3*(i-3), 3*dp[i-3]));
			}
			return dp[n];
		}
};

class Solution4 {
	public:
		int integerBreak(int n)
		{
			if(n <= 3)
			{
				return n - 1;
			}
			int quotient = n / 3;
			int remainder = n % 3;
			if (remainder == 0) {
				return (int) pow(3, quotient);
			} else if (remainder == 1) {
				return (int)pow(3, quotient - 1) * 4;
			} else {
				return (int)pow(3, quotient) * 2;
			}
		}
};


int test(int n)
{	
	Solution s;

	std::cout << n << " : " << s.integerBreak(n) << " : ";
	for(auto i : s.res)
	{
		std::cout << i << "\t";
	}
	std::cout << "\n";

}

int test2(int n)
{
	Solution2 s;
	std::cout << n << " : " << s.integerBreak(n) << " : ";
	std::cout << "\n";
}

int test3(int n)
{
	Solution3 s;
	std::cout << n << " : " << s.integerBreak(n) << " : ";
	std::cout << "\n";
}

int test4(int n)
{
	Solution4 s;
	std::cout << n << " : " << s.integerBreak(n) << " : ";
	std::cout << "\n";
}



int main()
{
	std::cout << "-----------------------\n";

	for(int i = 2; i < 58; i++)
	{
		test4(i);
		std::cout << "--------------------------------\n";
	}

}
