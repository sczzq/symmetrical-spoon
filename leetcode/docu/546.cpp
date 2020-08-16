#include "cppsczzq@sczzq-NBLK-WAX9X_header.h"

class Solution {
public:
	int removeBoxes(vector<int>& boxes)
	{
		/*
		int score = 0;
		map<int, int> nums;
		for(int i = 0; i < boxes.size(); i++)
		{
			nums[boxes[i]]++;
		}
		for(int i = 0; i < boxes.size(); i++)
		{
			if(nums[boxes[i]] == 1)
			{
				score += 1;
				boxes.erase(boxes.begin()+i);
				i--;
			}
		}
		*/

		return remove(boxes);
	}

	int remove(vector<int> boxes)
	{
		if(boxes.size() == 0)
			return 0;
		int res = 0;
		for(int i = 0, j = i+1; i < boxes.size(); i++)
		{
			while(j < boxes.size() && boxes[i] == boxes[j])
				j++;
			vector<int> newboxes(boxes.size() - (j-i));
			for(int k = 0, p = 0; k < boxes.size(); k++)
			{
				if(k == i)
					k = j;
				if(k < boxes.size())
					newboxes[p++] = boxes[k];
			}
			res = max(res, remove(newboxes) + (j-i)*(j-i));
		}
		return res;
	}
};

int testcase(vector<int> boxes, int res, int casenum)
{
	Solution sol;
	int cre = sol.removeBoxes(boxes);
	if(cre == res)
	{
		cout << casenum << " pass\n";
	}
	else
	{
		cout << casenum << " no pass\n";
		cout << cre << "\n";
		cout << "-----------------------\n";
	}
}

int main()
{
	vector<int> boxes;
	int res;
	int casenum;

	boxes = {1, 1, 1, 2, 2, 2, 1, 1, 1, 3};
	res = 3*3 + 6*6 + 1*1;
	casenum = 1;
	testcase(boxes, res, casenum);

	boxes = {1,3,2,2,2,3,4,3,1};
	res = 23;
	casenum = 2;
	testcase(boxes, res, casenum);

	boxes = {1, 1, 2, 1, 1, 3};
	res = 1*1 + 4*4 + 1*1;
	casenum = 3;
	testcase(boxes, res, casenum);

	boxes = {1, 1, 2, 2, 1, 1, 2, 3, 2, 3, 1, 4, 3, 3};
	res = 1*1 + 4*4 + 1*1;
	casenum = 4;
	testcase(boxes, res, casenum);


}

