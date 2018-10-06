/*************************************************************************
    > File Name: maxSlidingWindow.cpp
    > Author: zhuziqiang
    > Mail: ziqiang_free@163.com 
    > Created Time: 2018年08月19日 星期日 12时46分23秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;

void showVector(vector<int> &nums)
{
	for (auto i : nums) {
		cout << i << " ";
	}
	cout << endl;
}

// 方法2：利用双端队列，通过一系列入队和出队操作计算滑动窗口最大值
// 1. 数组元素从i=0开始入队，若新入队的元素大于前一个元素（即当前队尾），则把队尾元素剔除，因为此时队尾元素不可能为窗口的最大值；
// 2. 若新入队元素小于队尾，则保留队尾，同时新元素入队（因为随着窗口的移动，该元素有可能成为某个窗口最大值）
// 3. 随着新元素入队，要及时判断队头元素是否在当前窗口内：通过下标差是否>=k来判断，若不在窗口内，则将队头出列；否则暂时保留！
// 4. 通过上述操作，队头始终为当前窗口的最大值
vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
	// border cases 边界情况
	if (nums.empty() || k > nums.size() || k <= 0)
		return vector<int>();

	 deque<int> dq; // 队列中存放的下标

	 vector<int> res;

	 int n = nums.size();
	 // 先将前 size 个元素入队：这是第一个窗口
	 // 举例：先入队2 3 4， 队列中的元素为：4(2,3小于4，被剔除)

	 int i = 0;
	 for (; i < k; i++) {
		 //新入队元素大于队尾，剔除队尾
		 while (!dq.empty() && nums[i] >= nums[dq.back()] )
			 dq.pop_back();

		 dq.push_back(i);
	 } // 第一个窗口元素经过入队操作后，在队列中只剩下最大元素 4

	 res.push_back(nums[dq.front()]);

	 // 对于下标i=size~n-1的元素，每个元素都是对应窗口的最后一个元素
	 // 除第一个窗口，剩下窗口个数为 n-size
	 for (int i = k; i < n; i++) {
		 // 首先判断当前队头是否处在当前窗口内
		 if (i-dq.front() >= k)
			 dq.pop_front();
		 while( !dq.empty() && nums[i] >= nums[dq.back()] )
			 dq.pop_back();
		 dq.push_back(i);

		 // 队头为当前窗口最大值
		 res.push_back(nums[dq.front()]);
	 } //end for

	 return res;
 }


vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
	int last = 0;
	vector<int> result;
	for (int i = 0; i < nums.size() - k + 1; i++) {
		int max = nums[i];
		for (int j = 1; j < k; j++) {
			if (max < nums[i+j]) {
				max = nums[i+j];
			}
		}
		result.push_back(max);
		cout << max << ", ";
	}
	cout << endl;
	return result;
}

int main()
{
	vector<int> s = {
		1,3,-1,-3,5,3,6,7
	};
	vector<int> r = maxSlidingWindow(s, 3);

	s = {
		1,2,3,4,5,6,7
	};
	r = maxSlidingWindow(s,3);

	s = {
		7,6,5,4,3,2,1
	};
	r = maxSlidingWindow(s,3);

	cout << "---------------------------------------" << endl;

	s = {
		1,3,-1,-3,5,3,6,7
	};
	r = maxSlidingWindow2(s, 3);
	showVector(r);

	s = {
		1,2,3,4,5,6,7
	};
	r = maxSlidingWindow2(s,3);
	showVector(r);

	s = {
		7,6,5,4,3,2,1
	};
	r = maxSlidingWindow2(s,3);
	showVector(r);

}
