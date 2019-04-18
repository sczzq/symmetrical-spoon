#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <sys/time.h>
#include "utility.h"

using namespace std;

typedef struct Result Result;

struct Result {
	vector<int> vi;
	int cur_pos;
};

void show_vector(vector<int> &vi)
{
	for(auto & x : vi)
	{
		cout << x << ' ';
	}
	cout << endl;
}

int lis_dp(std::vector<int> &iseq)
{
	vector<int> vlis(iseq.size());
	vlis[0] = 1;

	for(int i = 1; i < iseq.size(); i++)
	{
		vlis[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (iseq[i] > iseq[j] && vlis[i] < vlis[j] + 1)
			{
				vlis[i] = vlis[j] + 1;
			}
		}
	}
	auto result = max_element(vlis.begin(), vlis.end());
	cout << "lis: " << *result << endl;
	return 0;
}

int longest_increasing_sequence(std::vector<int> &iseq)
{
	std::vector<Result> result_space;
	int cur_finished = 0, last_finished = 0;
	for(int i = 0; i < iseq.size(); i++)
	{
		Result result;
		result.cur_pos = 0;
		result.vi.push_back(iseq[i]);
		result_space.push_back(result);
		for(int k = 0; k < result_space.size(); )
		{
			int get_longer = 0;
			for(int j = i+1 ; j < iseq.size(); j++)
			{
				Result &r = result_space[k];
				vector<int> &vr = r.vi;
				if (r.cur_pos < j && vr[vr.size()-1] < iseq[j])
				{
					get_longer = 1;
					Result nr = result_space[k];
//					cout << "before insert:\n";
//					show_vector(r);
					nr.vi.push_back(iseq[j]);
//					cout << "after insert:\n";
//					show_vector(nr);
//					cout << endl;
					nr.cur_pos = j;
					result_space.push_back(nr);
				}
			}
//			if (get_longer == 1)
			{
//				result_space.erase(result_space.begin() + k);
			}
//			else
			{
				k++;
			}
		}
		cur_finished = result_space.size();
		for(int i = last_finished; i < cur_finished; i++)
		{
			result_space[i].cur_pos = iseq.size();
		}
//		cout << "finished: " << last_finished << " " << cur_finished << endl;
		last_finished = cur_finished;
	}
	int max_length = 0;
	int max_index = -1;
	vector<int> max;
	for (int i = 0; i < result_space.size(); i++)
	{
		if (max_length < result_space[i].vi.size())
		{
			max_length = result_space[i].vi.size();
			max_index = i;
		}
//		show_vector(result_space[i].vi);
	}
	cout << "total increasing sequence number: " << result_space.size() << endl;
	max = result_space[max_index].vi;
	show_vector(max);
	cout << "infinite search: " << max.size() << endl;
}

int test()
{
	std::vector<int> input;
	random_vector(input, 1, 20, 10);

	show_vector(input);
	longest_increasing_sequence(input);
	lis_dp(input);

}

int test2()
{
	vector<int> input{1,2,3,4,5,6,7,8};
	show_vector(input);
	longest_increasing_sequence(input);
	lis_dp(input);
}

int test3()
{
	vector<int> input{8,7,6,5,4,3,2,1};
	show_vector(input);
	longest_increasing_sequence(input);
	lis_dp(input);
}

int test4(int num)
{
	std::vector<int> input;
	random_vector(input, 1, 200000, num);

	cout << "vector size: " << num << endl;

//	show_vector(input);

	/*
	START_TIME;
	longest_increasing_sequence(input);
	END_TIME;
	*/

	{
		START_TIME;
		lis_dp(input);
		END_TIME;
	}
}


int main()
{
	test();
	test2();
	test3();
	test4(10);
	test4(20);
	test4(30);
	test4(40);
	test4(50);
	test4(60);
	test4(70);
	test4(80);
	test4(90);
	test4(100);
	test4(1000);
	test4(10000);
	test4(100000);
}

