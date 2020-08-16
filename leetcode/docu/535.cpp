#include "cpp_header.h"

class Solution {
	unordered_map<string, string> urls;
public:
	string encode(string longUrl)
	{
		string protocol;
		string domain;
		string directory;

		auto pos = longUrl.find_first_of(":");
		protocol = longUrl.substr(0, pos);

		auto pos2 = longUrl.find_first_of("/", pos+3);

		domain = longUrl.substr(pos+3, pos2 - pos - 3);

		if(pos2 != string::npos)
		{
			directory = longUrl.substr(pos2+1);
		}

		cout << protocol << ", " << domain << ", " << directory << "\n";

		string shortUrl_dom = getSixChar();
		string shortUrl_dir = getSixChar();

		urls[shortUrl_dom] = domain;
		if(!directory.empty())
		{
			urls[shortUrl_dir] = directory;
		}

		string shortUrl = "http://" + shortUrl_dom + ".com";
		if(!directory.empty())
		{
			shortUrl = shortUrl + "/" + shortUrl_dir;
		}

		cout << shortUrl << "\n";

		return shortUrl;
	}

	string decode(string shortUrl)
	{
		string protocol;
		string domain;
		string directory;

		auto pos = shortUrl.find_first_of(":");
		protocol = shortUrl.substr(0, pos);

		auto pos2 = shortUrl.find_first_of("/", pos+3);

		if(pos2 != string::npos)
		{
			domain = shortUrl.substr(pos+3, pos2 - pos - 3 - 4);
			directory = shortUrl.substr(pos2+1);
		}
		else
		{
			domain = shortUrl.substr(pos+3, shortUrl.length() - pos - 3 - 4);
		}

		cout << protocol << ", " << domain << ", " << directory << "\n";

		string longUrl_dom, longUrl_dir;

		longUrl_dom = urls[domain];
		if(!directory.empty())
		{
			longUrl_dir = urls[directory];
		}

		string longUrl;
		if(!longUrl_dom.empty())
		{
			longUrl = "https://" + longUrl_dom;
			if(!longUrl_dir.empty())
			{
				longUrl = longUrl + "/" + longUrl_dir;
			}
		}

		urls.erase(domain);
		urls.erase(directory);

		cout << longUrl << "\n";

		return longUrl;
	}


	int getRandom()
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distribu(0, 61);

		return distribu(gen);
	}

	string getSixChar()
	{
		string s;
		s += getChar(getRandom());
		s += getChar(getRandom());
		s += getChar(getRandom());
		s += getChar(getRandom());
		s += getChar(getRandom());
		s += getChar(getRandom());

		return s;
	}

	char getChar(int rdm)
	{
		if(rdm > 51)
		{
			return (rdm - 52) + '0';
		}
		else if(rdm > 25)
		{
			return (rdm - 26) + 'A';
		}
		else {
			return rdm + 'a';
		}
	}
};

int main()
{
	string longUrl = "https://leetcode.com/problems/design-tinyUrl";

	{
		Solution sol;

		sol.decode(sol.encode(longUrl));
		cout << "-------------------------------------------\n";
		sol.decode(sol.encode(longUrl));
		cout << "-------------------------------------------\n";
	}

	{
		Solution sol;
		sol.decode(sol.encode(longUrl));
		cout << "-------------------------------------------\n";
	}


	longUrl = "https://page.leetcode.com,cn/problems/design-tinyUrl";
	{
		Solution sol;

		sol.decode(sol.encode(longUrl));
		cout << "-------------------------------------------\n";
		sol.decode(sol.encode(longUrl));
		cout << "-------------------------------------------\n";
	}

	{
		Solution sol;
		sol.decode(sol.encode(longUrl));
		cout << "-------------------------------------------\n";
	}

	longUrl = "https://page.leetcode.com.cn";
	{
		Solution sol;

		sol.decode(sol.encode(longUrl));
		cout << "-------------------------------------------\n";
	}

	longUrl = "https://page.leetcode.com.cn/";
	{
		Solution sol;

		sol.decode(sol.encode(longUrl));
		cout << "-------------------------------------------\n";
	}


}

