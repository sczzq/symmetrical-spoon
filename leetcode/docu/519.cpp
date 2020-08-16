#include "cpp_header.h"

class Solution {
	bool *matrix;
	int size;
	int capacity;
	int rows;
	int cols;
	random_device rd;
	mt19937 gen;
	uniform_int_distribution<> distribu;
public:
	Solution(int n_rows, int n_cols)
	{
		rows = n_rows;
		cols = n_cols;
		size = 0;
		capacity = rows*cols;
		matrix = new bool[capacity];

		for(int i = 0;i < capacity*cols; i++)
		{
			matrix[i] = 0;
		}

		gen = mt19937(rd());
		distribu = uniform_int_distribution<>(0, capacity-1);
	}

	vector<int> flip()
	{
		vector<int> res;

		if(size == capacity)
		{
			return res;
		}

		int rdm = distribu(gen);

		while(matrix[rdm] == 1)
		{
			rdm = distribu(gen);
		}
		matrix[rdm] = 1;
		size++;

		res.push_back(rdm / rows);
		res.push_back(rdm % rows);

		return res;
	}

	void reset()
	{
		for(int i = 0; i < rows*cols; i++)
		{
			matrix[i] = 0;
		}
		size = 0;
	}

};

int main()
{
	Solution sol(2,3);
	vector<int> res;

	res = sol.flip();
	for(auto x : res)
		cout << x << " ";
	cout << "\n";

	res = sol.flip();
	for(auto x : res)
		cout << x << " ";
	cout << "\n";

	res = sol.flip();
	for(auto x : res)
		cout << x << " ";
	cout << "\n";

	res = sol.flip();
	for(auto x : res)
		cout << x << " ";
	cout << "\n";

	res = sol.flip();
	for(auto x : res)
		cout << x << " ";
	cout << "\n";

	res = sol.flip();
	for(auto x : res)
		cout << x << " ";
	cout << "\n";

	res = sol.flip();
	for(auto x : res)
		cout << x << " ";
	cout << "\n";

	res = sol.flip();
	for(auto x : res)
		cout << x << " ";
	cout << "\n";

}

