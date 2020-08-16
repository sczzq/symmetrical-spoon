#include "cpp_header.h"


/*
 * vecotr[0]: 0 - 999,999,99
 * vector[1]: 0 - 999,999,99
 * ...
 *
 *
 * */
class big_num {
	vector<int> nums;
	int big_base = 99999999;
public:
	big_num() {
		nums = vector<int>(2, 0);
	};

	int plus(int k);
	int plus(big_num bk);

	int minus(int k);
	int minus(big_num bk);

	int size()
	{
		return nums.size();
	}

	void show();
};

int big_num::plus(int k)
{
	nums[0] += k;

	for(int i = 0; i < nums.size() - 1; i++)
	{
		while(nums[i] > big_base)
		{
			nums[i] -= big_base;
			nums[i+1]++;
		}
	}
	if(nums.back() > big_base)
	{
		nums.back() -= big_base;
		nums.push_back(1);
	}

	return 0;
}

int big_num::plus(big_num bk)
{
	int max_size = bk.size() > nums.size() ? bk.size() : nums.size();
	nums.reserve(max_size + 1);
}



