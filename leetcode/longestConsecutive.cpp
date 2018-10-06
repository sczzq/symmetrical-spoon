/*************************************************************************
    > File Name: longestConsecutive.cpp
    > Author: zhuziqiang
    > Mail: ziqiang_free@163.com 
    > Created Time: 2018年08月19日 星期日 00时43分39秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

int longestConsecutive3(vector<int> &nums)
{
	if (nums.size() < 2){
		return nums.size();
	}
	int re(1);
	sort(nums.begin(), nums.end());
	int index(1);
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] - nums[i-1] == 1) {
			++index;
		}
		else if (nums[i] == nums[i - 1]){
			continue;
		}
		else {
			index = 1;
		}
		re = max(re, index);
	}
	re = max(re, index);
	return re;
}

int longestConsecutive2(vector<int> &nums)
{
	unordered_set<int> uset;
	for (int num : nums) {
		uset.insert(num);
	}
	int longest = 0;
	for (int num : uset) {
		if (uset.find(num-1) == uset.end()) {
			int cnt = 1;
			while (uset.find(num + 1) != uset.end()) {
				num++;
				cnt++;
			}
			longest = max(longest, cnt);
		}
	}
	return longest;
}

int longestConsecutive(vector<int> &nums)
{
	unordered_map<int, int> hm;
	int max = 0;

	for(auto it = nums.begin(); it != nums.end(); it++) {
		hm[*it] = 1;
	}

	for(auto it = hm.begin(); it != hm.end(); it++) {
		int k = it->first;
		cout << "first: " << it->first << ", second: " << it->second << endl;
		k++;
		for (auto it2 = hm.find(k); it2 != hm.end(); it2 = hm.find(k)){
			it->second += it2->second;
			cout << "k: " << k << ", max: " << max << endl;
			if (it2->second != 1) {
				break;
			}
			k++;
		}
		if (max < it->second) {
			max = it->second;
		}
	}
	cout << "---------------" << endl;
	return max;
}

int main()
{
	vector<int> s ={
		100,400,4,200,1,3,2
	};
	cout << longestConsecutive2(s) << endl;

	s ={
		1,2,0,1
	};
	cout << longestConsecutive2(s) << endl;

	s ={
		0,3,7,2,5,8,4,6,0,1
	};
	cout << longestConsecutive2(s) << endl;
}

