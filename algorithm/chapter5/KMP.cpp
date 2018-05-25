/*************************************************************************
	> File Name: KMP.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月24日 星期四 19时46分25秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <exception>

using std::string;
using std::vector;
class KMP{
	private:
		string pattern;
		vector<vector<int>> dfa;
	public:
		/*
		 * construct dfa from pattern.
		 *
		 * dfa is two-dimen vector,
		 * the row is the character, or the object in pattern,
		 * the column is the next state or next column in pattern,
		 *
		 * init state:
		 *	dfa[pattern.at(0)][0] set to 1,
		 *	this is the first column of dfa
		 *	that is to say,
		 *		if donot get the first character in pattern
		 *		then, the state of next character is 0 position
		 *		otherwise, the next state is dfa[char][0]
		 *
		 * update strategy:
		 *	current state, X,
		 *	current position in pattern, j
		 *	copy the column of X to column j
		 *	update [p[j]][j] to j + 1
		 *	   (row, column) to column + 1.
		 *	update X to [p[j]][X].
		 *
		 */
		KMP(string pat) 
			: pattern{pat}
		{
			int M = pattern.length();
			const int R = 256;
			// construct dfa.
			for(int i = 0; i < R; i++){
				vector<int> niv;
				niv.resize(M);
				dfa.push_back(niv);
			}
			int cc = int{pattern.at(0)};
			dfa.at(cc).at(0) = 1;
			for(int X = 0, j = 1; j < M; j++){
				for(int c = 0; c < R; c++){
					dfa[c][j] = dfa[c][X];
				}
				cc = int{pattern[j]};
				dfa[cc][j] = j + 1;
				X = dfa[cc][X];
			}
		}

		int show_dfa()
		{
			std::cout << "pattern: " << pattern << std::endl;
			int i = 0;
			for(auto & x : dfa){
				std::cout << i++ << ": ";
				for(auto & y : x)
					std::cout << y << " ";
				std::cout << std::endl;
			}
		}

		/*
		 * dfa is the definitely finite state machine.
		 * its row is current character in text or pattern,
		 * its column is the next state, or next column in dfa.
		 * if get the position after the end of pattern, then find out,
		 * then if get the position after the end of text, then not find out.
		 *
		 * init state: 
		 *	position in text is 0, mark as t0
		 *	position in column is 0, mark as X
		 *
		 * update strategy:
		 *	update current column to dfa[text[t0]][X],
		 *	update current text position as t0+1;
		 *
		 * boundary condition:
		 *	up to end of pattern.
		 *	up to end of text.
		 *
		 */
		int search(string text)
		{
			int i, X, N = text.length(), M = pattern.length();
			int cc = 0;
			for(i = 0, X = 0; i < N && X < M; i++){
				cc = int{text.at(i)};
				X = dfa[cc][X];
			}
			if(X == M) return i - M; // find out the pattern in text.
						// up to the end of pattern string.
			else return N; // not find out the pattern in text.
					// up to the end of text string.
		}
};

int main()
{
	try{
		string text{"bcbaabacaababacaa"};
		string tet2{"bcbaabacaaasdfasdfasfasfasfasf"};
		string pattern{"ababac"};

		KMP kmp(pattern);
		kmp.show_dfa();

		std::cout << kmp.search(text) << std::endl;
		std::cout << text << ", length " << text.length() << std::endl;

		std::cout << kmp.search(tet2) << std::endl;
		std::cout << tet2 << ", length " << tet2.length() << std::endl;

		KMP mp1("abababab");
		std::cout << "abababab" << std::endl;
		KMP mp2("abcababc");
		std::cout << "abcababc" << std::endl;
		KMP mp3("abcabcabc");
		std::cout << "abcabcabc" << std::endl;

	} catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

}
