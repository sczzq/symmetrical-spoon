#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
 * 给定一个数组array，给定一个正整数w
 * 假设数组的大小大于w
 * 输出数组中所有连续w个数的最大值和最小值的差的最大的绝对值。
 * 也就是，对于连续的w个数，其中有最大值和最小值，计算最大值和最小值的差的绝对值，
 * 需要输出所有连续w个数的最大的绝对值。
 *
 * 举例
 * 数组 1 4 3 4 2 6
 * w = 3
 *
 * 总共有四组连续的3个数
 * 1 4 3
 * 4 3 4
 * 3 4 2
 * 4 2 6
 * 每组中的最大值和最小值以及最大值和最小值的差的绝对值分别为
 * 最大值	最小值	差的绝对值
 * 4		1		3
 * 4		3		1
 * 4		2		2
 * 6		2		4
 * 那么，输出就是 4，表示差的绝对值的最大值。
 */

static int absminus(int x, int y)
{
	return x > y ? x - y : y - x;
}

int slice_windows(vector<int> vi, int w)
{
	int min, max, maxabs;
	std::set<int> si;

	for (auto x : vi)
		cout << x << " ";
	cout << endl;

	if (vi.size() < 0 || vi.size() < w || w < 1)
		return -1;

	maxabs = 0;

	si.insert(vi.begin(), vi.begin() + w);

	for (auto x : si)
		cout << x << " ";
	cout << endl;

	int left = vi[0];
	min = *si.begin();
	max = *(si.rbegin());
	maxabs = absminus(min, max);
	cout << "min: " << min << ", max:" << max << ", maxabs: " << maxabs << endl;

	for(int i = w; i < vi.size(); i++)
	{
		si.erase(left);
		if (si.size() < w-1)
			si.insert(left);
		si.insert(vi[i]);
		left = vi[i - w + 1];
		int lmin = *si.begin();
		int lmax = *(si.rbegin());
		int lmaxabs = absminus(lmin, lmax);

		cout << "lmin: " << lmin << ", lmax:" << lmax << ", lmaxabs: " << lmaxabs << endl;
		if (lmaxabs > maxabs)
		{
			min = lmin;
			max = lmax;
			maxabs = lmaxabs;
		}
		for (auto x : si)
			cout << x << " ";
		cout << endl;
		cout << "min: " << min << ", max:" << max << ", maxabs: " << maxabs << endl;
	}
}

int test()
{
	vector<int> vi {1,4,3,4,2,6};
	slice_windows(vi, 3);
}
int main()
{
	test();
}
