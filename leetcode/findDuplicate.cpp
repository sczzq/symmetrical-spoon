/*************************************************************************
    > File Name: findDuplicate.cpp
    > Author: zhuziqiang
    > Mail: ziqiang_free@163.com 
    > Created Time: 2018年08月19日 星期日 10时29分33秒
 ************************************************************************/

/*
 * 寻找重复数
 *
 * 200~给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
 *
 * 示例 1:

	输入: [1,3,4,2,2]
	输出: 2



	示例 2:

	输入: [3,1,3,4,2]
	输出: 3

    不能更改原数组（假设数组是只读的）。
    只能使用额外的 O(1) 的空间。
    时间复杂度小于 O(n2) 。
    数组中只有一个重复的数字，但它可能不止重复出现一次。

 */

#include<iostream>
#include<vector>

using namespace std;

int findDuplicate2(const vector<int> &nums)
{
	int sum1 = 0, sum2 = 0;
	for ( int i = 0; i < nums.size() - 1; i++) {
		sum1 += i + 1;
		sum2 += nums[i];
	}
	sum2 += nums[nums.size() - 1];

	for (auto i : nums) {
		for (auto j : nums) {
		}
	}
	return 0;
}

int findDuplicate(const vector<int> &nums)
{
	int i = 0;
	for( auto it = nums.begin(); it != nums.end(); it++) {
		for (auto it2 = it + 1; it2 != nums.end(); it2++) {
			if (*it == *it2) {
				return *it;
			}
		}
	}
	return 0;
}

int main()
{

	vector<int> s = {
		1,3,4,2,2
	};
	cout << findDuplicate(s) << endl;

	s = {
		3,1,3,4,2
	};
	cout << findDuplicate(s) << endl;
}

