#include "cpp_header.h"

class Solution {
	int min_price = INT_MAX;
public:
	int shoppingOffers(vector<int>& price, vector<vector<int>> & special, vector<int>& needs) 
	{
		vector<int> cur_needs = needs;
		for(int i = 0; i < special.size(); i++)
		{
			getPrice(0, price, special, needs);
		}

		int single_price = 0;
		for(int i = 0; i < needs.size(); i++)
		{
			single_price += needs[i] * price[i];
		}

		return min(min_price, single_price);
	}

	void getPrice(int last_price, vector<int>& price, vector<vector<int>> &special, vector<int>& needs)
	{
		int mark = 0;
		if(last_price >= min_price)
		{
			return;
		}
		if(accumulate(needs.begin(), needs.end(), 0) == 0)
		{
			min_price = min(min_price, last_price);
			return;
		}
		for(int i = 0; i < special.size(); i++)
		{
			if(is_eg(needs, special[i]))
			{
				// donot create new element in iterator
				for(int j = 0; j < needs.size(); j++)
				{
					needs[i] -= special[i][j];
				}

				getPrice(special[i].back() + last_price, price, special, needs);

				for(int j = 0; j < needs.size(); j++)
				{
					needs[i] += special[i][j];
				}
				mark = 1;
			}
		}
		// no special, use price list and current needs to get total_price.
		if(mark == 0)
		{
			int total_price = last_price;
			for(int i = 0; i < price.size(); i++)
			{
				total_price += price[i] * needs[i];
			}
			if(total_price < min_price)
			{
				min_price = total_price;
			}
		}
	}

	// v1 - v2, v1.size() <= v2.size()
	vector<int> minus(vector<int> & v1, vector<int> & v2)
	{
		vector<int> dm;
		for(int i = 0; i < v1.size(); i++)
		{
			dm.push_back(v1[i]-v2[i]);
		}
		return dm;
	}

	// check v1 is equal or greater than v2
	// v1.size() <= v2.size()
	bool is_eg(vector<int> & v1, vector<int> & v2)
	{
		for(int i = 0; i < v1.size(); i++)
		{
			if(v1[i] < v2[i])
			{
				return false;
			}
		}
		return true;
	}

	void show_vector(vector<int> & v)
	{
		for(auto x : v)
		{
			cout << x << " ";
		}
		cout << "\n";
	}


};

int main()
{
	Solution s;

	vector<int> price{2,5};
	vector<vector<int>> special{{3,0,5}, {1,2,10}};
	vector<int> needs{3,2};

	cout << s.shoppingOffers(price, special, needs) << "\n";

	price = {2,3,4};
	special = {{1,1,0,4}, {2,2,1,9}};
	needs = {1,2,1};
	cout << s.shoppingOffers(price, special, needs) << "\n";
}

