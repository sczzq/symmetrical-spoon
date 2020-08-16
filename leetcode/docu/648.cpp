#include "cpp_header.h"

class Solution {
public:
	string replaceWords(vector<string>& dict, string sentence)
	{
		size_t s_pos = 0;
		size_t e_pos;

		string res;

		map<string, string> word_dict;
		vector<string> words;

		do {
			string word;
			e_pos = sentence.find_first_of(" ", s_pos);

			if(e_pos != string::npos)
			{
				word = sentence.substr(s_pos, e_pos - s_pos);
			}
			else
			{
				word = sentence.substr(s_pos, sentence.length() - s_pos);
			}

			words.push_back(word);

			cout << word << "----\n";

			string lsd;
			for(auto & sd : dict)
			{
				if(start_with(word, sd))
				{
					if(lsd.length() == 0)
					{
						lsd = sd;
					}
					else
					{
						if(lsd.length() > sd.length())
						{
							lsd = sd;
						}
					}
				}
				
			}

			if(lsd.length() > 0)
			{
				word_dict[word] = lsd;
			}

			s_pos = e_pos + 1;

		} while( e_pos != string::npos );

		for(int i = 0; i < words.size(); i++)
		{
			string word = words[i];
			if(word_dict.find(word) != word_dict.end())
			{
				res += word_dict[word];
			}
			else
			{
				res += word;
			}

			if((i + 1) < words.size())
			{
				res += " ";
			}
		}


		return res;
	}

	bool start_with(string & word, string & dic)
	{
		int least = min(word.length(), dic.length());
		if(word.length() < dic.length())
		{
			return false;
		}
		for(int i = 0; i < least; i++)
		{
			if(word[i] != dic[i])
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution s;

	vector<string> dict {"cat", "bat", "rat"};
	string sentence {"the cattle was rattled by the battery"};

	cout << s.replaceWords(dict, sentence) << "---\n";

#include "648_testcase"
	cout << s.replaceWords(dict22, sentence) << "---\n";
}


