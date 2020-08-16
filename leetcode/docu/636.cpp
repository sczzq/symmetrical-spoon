#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	struct Task {
		int id;
		int status;
		int timepoint;
		int timepoint_type = 1; // 1 start, 2 end
		int elapsed = 0;
	};

	/*
	 * status: 1 start, 2 end, 3 pause
	 */
	vector<int> exclusiveTime(int n, vector<string>& logs) {
		list<Task> tasks;
		vector<int> res(n, 0);
		int last_status = 1; // maybe 1 or 2, mark start or end of timestamp

		for(auto & s : logs)
		{
			Task t;
			//--------------------------------------
			auto pos = s.find_first_of(':', 0);
			t.id = stoi(s.substr(0, pos));
			if(s[pos+1] == 's'){
				t.status = 1;
				t.timepoint_type = 1;
			} else {
				t.status = 2;
				t.timepoint_type = 2;
			}

			auto spos = s.find_first_of(':', pos+1);
			t.timepoint = stoi(s.substr(spos+1));

			cout << t.id << ":" << t.status << ":" << t.timepoint << "\n";
			//--------------------------------------

			if(tasks.size() == 0)
			{
				tasks.push_back(t);
			}
			else
			{
				auto &lt = tasks.back();

				if(t.status == 2) { // end a task, its id must be same as lt.id
					res[t.id] += t.timepoint - lt.timepoint + lt.elapsed;
					if (lt.timepoint_type == 1) // end-start, plus 1
					{
						res[t.id] += 1;
					}

					tasks.pop_back();

					if(tasks.size() > 0)
					{
						auto &llt = tasks.back();
						llt.timepoint = t.timepoint;
						llt.timepoint_type = t.timepoint_type;
						llt.status = 1;
					}
				}
				else  // start of a task, maybe pause last task
				{
					lt.status = 3;
					lt.elapsed += t.timepoint - lt.timepoint;
					if(lt.timepoint_type == 2){ // start - end, minus 1
						lt.elapsed--;
					}

					lt.timepoint = t.timepoint;
					lt.timepoint_type = t.status;

					tasks.push_back(t);
				}
			}
		}

		return res;
	};
};

int main()
{
	Solution s;
	vector<int> res;

	vector<string> logs{"0:start:0", "1:start:2", "1:end:5", "0:end:6"};

	res = s.exclusiveTime(2, logs);

	for(int i = 0; i < res.size(); i++)
	{
		cout << i << ", " << res[i] << "\n";
	}

	vector<string> logs2{"0:start:0", "1:start:2", "1:end:5", "2:start:6", "2:end:7", "0:end:8"};

	res = s.exclusiveTime(3, logs2);

	for(int i = 0; i < res.size(); i++)
	{
		cout << i << ", " << res[i] << "\n";
	}

}

