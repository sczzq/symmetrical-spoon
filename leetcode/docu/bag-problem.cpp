#include "cpp_header.h"

class BagSolution {
public:
	/*
	 * each things just has one.
	 */
	int ZeroOnePack(vector<int> weights, vector<int> values, int bag_capacity)
	{
		/*
		 * max_value[i][j]
		 *   pre i'th things
		 *   total weight less than j
		 *   max value
		 */
		vector<vector<int>> max_value(weights.size()+1, vector<int>(bag_capacity+1, 0));

		for(int i = 1; i <= weights.size(); i++)
		{
			for(int j = bag_capacity; j > 0; j--)
			{
				if(weights[i] <= j)
				{
					max_value[i][j] = max(max_value[i-1][j], max_value[i-1][j-weights[i]]+values[i]);
				}
				else
				{
					max_value[i][j] = max_value[i-1][j];
				}
			}
		}

		return max_value[weights.size()][bag_capacity];
	}

	/*
	 * each things just has one.
	 */
	int ZeroOnePack2(vector<int> weights, vector<int> values, int bag_capacity)
	{
		/*
		 * max_value[j]
		 * 	weight less than j
		 * 	max value
		 */
		vector<int> max_value(bag_capacity+1, 0);

		for(int i = 1; i <= weights.size(); i++)
		{
			for(int j = bag_capacity; j >= weights[i]; j--)
			{
				max_value[j] = max(max_value[j], max_value[j-weights[i]] + values[i]);
			}
		}

		return max_value[bag_capacity];
	}


	/*
	 * each things can get repetitively.
	 */
	int CompletePack(vector<int> weights, vector<int> values, int bag_capacity)
	{
		/*
		 * max_value[j]
		 * 	weight less than j
		 * 	max value
		 */
		vector<int> max_value(bag_capacity+1, 0);

		for(int i = 1; i <= weights.size(); i++)
		{
			for(int j = weights[i]; j <= bag_capacity; j++)
			{
				max_value[j] = max(max_value[j], max_value[j-weights[i]] + values[i]);
			}
		}

		return max_value[bag_capacity];
	}


	/*
	 * each things can get exactly times.
	 */
	int MultiPack(vector<int> weights, vector<int> values, vector<int> numbers, int bag_capacity)
	{
		vector<int> max_value(bag_capacity + 1, 0);
		for(int i = 1; i <= weights.size(); i++)
		{
			for(int j = bag_capacity; j >= weights[i]; j--)
			{
				for(int k = 0; k <= numbers[i]; k++)
				{
					if(j - k * weights[i] < 0)
						break;
					max_value[j] = max(max_value[j], max_value[j - k * weights[i]] + k * values[i]);
				}
			}
		}

		return max_value[bag_capacity];
	}

	/*
	 * two capacity
	 * 474
	 * dp[i][j] = max(dp[i][j], 1 + dp[i - cost_zero[0], j - cost_one[k]]) if i >= cost_zero[k] and j >= cost_one[k]
	 */


};




