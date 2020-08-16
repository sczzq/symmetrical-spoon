#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int minimalSteps(vector<string>& maze) {
		int width = maze.size();
		int length = maze[0].length();

		vector<vector<int>> entry, target, stones, walls, jacks;

		for(int i = 0; i < maze.size(); i++)
		{
			for(int j = 0; j < maze[i].length(); j++)
			{
				if(maze[i][j] == 'O')
				{
					stones.push_back({i, j});
				}
				else if(maze[i][j] == 'M')
				{
					jacks.push_back({i, j});
				}
				else if(maze[i][j] == '#')
				{
					walls.push_back({i, j});
				}
				else if(maze[i][j] == 'S')
				{
					entry.push_back({i, j});
				}
				else if(maze[i][j] == 'T')
				{
					target.push_back({i, j});
				}
			}
		}

	}
};


