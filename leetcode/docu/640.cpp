#include "cpp_header.h"

class Solution {
public:
	string solveEquation(string equation)
	{
        string res;
		int bitwise = 0;
		vector<string> pieces;
		cout << equation << "\n";

		if(equation[0] == '-' || equation[0] == '+')
		{
			equation = "0" + equation;
		}
		{
			auto poss = equation.find_first_of('=');
			if(equation[poss+1] == '-' || equation[poss+1] == '+')
			{
				equation.insert(poss+1, "0");
			}
		}
		for(size_t i = 0; i < equation.length(); i++)
		{
			string piece;
			piece += equation[i];
			for(size_t j = i + 1; j < equation.length(); j++)
			{
				i = j;
				if(equation[j] == '+' 
						|| equation[j] == '-' 
						|| equation[j] == '=' )
				{
					pieces.push_back(piece);

					string ops{equation[j]}; 
					if(equation[j] == '='){
						ops = "-";
						bitwise = 1;
					}
					else if(bitwise == 1)
					{
						if(equation[j] == '-')
						{
							ops = "+";
						}
						else if (equation[j] == '+')
						{
							ops = "-";
						}
					}
					pieces.push_back(ops);

					break;
				}
				piece += equation[j];
			}
			if(i + 1 == equation.length())
			{
				pieces.push_back(piece);
			}
		}

        /*
        */
		for(auto x : pieces)
		{
			cout << x << " ";
		}
		cout << "\n";

		int coff_sum = 0;
		int integer_sum = 0;
		char ops = 0;
		for(auto &piece : pieces)
		{
			if(*(piece.rbegin()) == 'x')
			{
				int len = piece.length();
				int coff;
				
				if(len == 1)
				{
					coff = 1;
				}
				else
				{
					coff = stoi(piece.substr(0, len-1));
				}

				if(ops == 0 || ops == '+')
				{
					coff_sum += coff;
				}
				else if(ops == '-')
				{
					coff_sum -= coff;
				}
			}
			else if(piece[0] == '-' || piece[0] == '+')
			{
				ops = piece[0];
			}
			else
			{
				int integer = stoi(piece);
				if(ops == '+' || ops == 0)
				{
					integer_sum += integer;
				}
				else if(ops == '-')
				{
					integer_sum -= integer;
				}
			}
		}
		cout << "x coff: " << coff_sum << "; integer value: " << integer_sum << "\n";

		if(coff_sum == 0 && integer_sum == 0)
		{
			res = "Infinite solutions";
		}
		else if(coff_sum == 0 && integer_sum != 0)
		{
			res = "No solution";
		}
		else if(coff_sum != 0 && integer_sum == 0)
		{
			res = "x=0";
		}
		else if(coff_sum != 0 && integer_sum != 0)
		{
			int r = integer_sum / coff_sum;
			r = -r;

			res = "x=";
			res += to_string(r);
		}

		return res;
	
    }
	
};


int main()
{
	Solution s;

	string equation;

	equation = "x+5-3+x=6+x-2";
	cout << s.solveEquation(equation) << "\n";
	cout << "--------------------------------------------\n";

	equation = "x=x";
	cout << s.solveEquation(equation) << "\n";
	cout << "--------------------------------------------\n";

	equation = "2x=x";
	cout << s.solveEquation(equation) << "\n";
	cout << "--------------------------------------------\n";

	equation = "2x=x-123123";
	cout << s.solveEquation(equation) << "\n";
	cout << "--------------------------------------------\n";

	equation = "2x+123=123-x-123123";
	cout << s.solveEquation(equation) << "\n";
	cout << "--------------------------------------------\n";

	equation = "-x=-1";
	cout << s.solveEquation(equation) << "\n";
	cout << "--------------------------------------------\n";


}

