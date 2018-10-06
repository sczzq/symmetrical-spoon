/*************************************************************************
    > File Name: firstMissingPositive.cpp
    > Author: zhuziqiang
    > Mail: ziqiang_free@163.com 
    > Created Time: 2018年08月18日 星期六 20时41分45秒
 ************************************************************************/

/*
 * more
 *	a set,
 *		1, comparable, less, equal, greater
 *		2, finite 精度
 */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Tracer {
	public:
		Tracer () {
			cout << "in ----------------------" << endl;
		};
		~Tracer() {
			cout << "out ----------------------" << endl;
		}
};

void showVector(vector<int> &nums)
{
	for (int i = 0; i < nums.size(); i++){
		cout << nums[i] << " ";
	}
	cout << endl;
}

int findFirstPositive(const vector<int> &nums)
{
	for(int i = 0; i < nums.size(); i++) {
		if (nums[i] > 0) {
			return i;
		}
	}
	return -1;
}

int findFirstMismatch(const vector<int> &nums)
{
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > 0 && nums[i] < nums.size() && i != nums[i] - 1) {
			return i;
		}
	}
	return -1;
}

int firstMissingPositive(vector<int> &nums)
{
	int k = 0, v = 0;
	int count = 0;
	for (k = findFirstMismatch(nums); k != -1; k = findFirstMismatch(nums)){
		v = nums[k];
		swap(nums[v - 1], nums[k]);
		if (nums[k] == nums[v-1]) {
			nums[k] = 0;
		}
		count++;
	}

	for (k = 0; k < nums.size(); k++) {
		if (nums[k] - 1 != k)
			break;
	}
	k++;

	cout << "count: " << count << endl;

	cout << k << endl;

	return k;
}

int main()
{
	vector<int> s = {
		1,2,0
	};
	showVector(s);
	firstMissingPositive(s);

	s = {
		1,1
	};
	showVector(s);
	firstMissingPositive(s);

	s = {
		1,2,2,2
	};
	showVector(s);
	firstMissingPositive(s);
	showVector(s);

	s = {
		3,4,-1,1
	};
	showVector(s);
	firstMissingPositive(s);

	s = {
		8,9,9,10,12
	};
	showVector(s);
	firstMissingPositive(s);

	s = {
		1,8,10,2,18
	};
	showVector(s);
	firstMissingPositive(s);

	s = {
		91,8,1,2,18
	};
	showVector(s);
	firstMissingPositive(s);

	s = {
		6,12,3,91,8,1,2,18,4,5,9
	};
	showVector(s);
	firstMissingPositive(s);
}

