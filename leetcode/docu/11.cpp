#include "cpp_header.h"

class Solution {
public:
	int myArea2(vector<int>& height)
	{
		int max_area = 0;
		for(int i = 0; i < height.size(); i++)
		{
			for(int j = i + 1; j < height.size(); j++ )
			{
				int cur_area = min(height[i], height[j]) * (j - i);
				if(cur_area > max_area)
					max_area = cur_area;
			}
		}

		return max_area;
	}

	int myArea(vector<int>& height)
	{
		int max_area = 0;
		int min_height = INT_MIN, s, e;

		for(int i = 0, j = height.size() - 1; i != j; )
		{
			if(height[i] <= min_height)
			{
				i++;
				continue;
			}
			if(height[j] <= min_height)
			{
				j--;
				continue;
			}

			min_height = min(height[i], height[j]);
			int cur_area = min_height * (j - i);
			if(cur_area > max_area)
				max_area = cur_area;
		}

		return max_area;
	}
};

int main()
{
	vector<int> height;
	int res;
	int casenum;

	height = {1,8,6,2,5,4,8,3,7};
	res = 49;
	casenum = 1;
	TESTCASE_p1(myArea, height, res, casenum);


}

