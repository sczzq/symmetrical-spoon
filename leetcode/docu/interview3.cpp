#include <iostream>

#include <vector>
#include <string>
#include <map>

using namespace std;

struct File {
	string path;
	string name;
	string content;
};

class Solution {
public:
	vector< vector < string > > findDuplicate(vector<string> paths) {
		vector<vector<string>> result;
		vector<File> files;

		for(auto s : paths)
		{
			size_t pos = 0;
			pos = s.find_first_of(' ', pos);
			if(pos != string::npos)
			{
				string path = s.substr(0, pos);
				size_t next_pos;
				pos++;
				while( pos < s.length() - 1)
				{
					next_pos = s.find_first_of(' ', pos);
					if(next_pos != string::npos)
					{
						string namecontent = s.substr(pos, next_pos - pos);
						cout << namecontent << "\n";
						pos = next_pos + 1;

						File f;
						f.path = path;

						size_t start = namecontent.find_first_of('(', 0);
						size_t end = namecontent.find_first_of(')', start);
						f.name = namecontent.substr(0, start);
						f.content = namecontent.substr(start+1, end-start-1);

						cout << f.path << ":" << f.name << ":" << f.content << "\n";
						files.push_back(f);
					}
					else
					{
						string namecontent = s.substr(pos, s.length() - pos);
						cout << namecontent << "\n";

						File f;
						f.path = path;

						size_t start = namecontent.find_first_of('(', 0);
						size_t end = namecontent.find_first_of(')', start);
						f.name = namecontent.substr(0, start);
						f.content = namecontent.substr(start+1, end-start-1);

						cout << f.path << ":" << f.name << ":" << f.content << "\n";

						files.push_back(f);
						break;
					}
				}
			}
			else
			{
				// null directory
			}
		}


		map<string, vector<string>> sta;
		for(auto & s : files)
		{
			cout << "-----------\n";
			sta[s.content].push_back(s.path+"/"+s.name);
		}

		for(auto & ms : sta)
		{
			if(ms.second.size() > 1)
			{
				result.push_back(ms.second);
				cout << ms.first << "\n";
			}
			cout << ms.second.size() << "\n";
		}


		return result;
	}
};

int main()
{
	vector<string> paths;

	string s1{"root/a 1.txt(abcd) 2.txt(efgh)"};
	string s2{"root/c 3.txt(abcd)"};
	string s3{"root/c/d 4.txt(efgh)"};
	string s4{"root 4.txt(efgh)"};
	paths.push_back(s1);
	paths.push_back(s2);
	paths.push_back(s3);
	paths.push_back(s4);

	Solution s;
	try{
		vector<vector<string>> res = s.findDuplicate(paths);
		cout << "[";
		for(auto re : res)
		{
			cout << "[";
			for(auto r : re)
			{
				cout << "\"" << r << "\",";
			}
			cout << "],";
		}
		cout << "]\n";
	}
	catch(const std::out_of_range & e){
		cout << "out of range\n";
	};


}


