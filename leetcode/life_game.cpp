#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

bool isLife(vector<vector<int>> &board, int x, int y)
{
	if (x >= 0 && y >= 0 && x < board.size() && y < board[x].size()){
		if (board[x][y] == 1) {
			return true;
		}
	}
	return false;
}

void gameOfLife(vector<vector<int>> &board)
{
	//vector<vector<int>> shadow = board;
	vector<vector<int>> shadow (board.begin(), board.end());
	for (auto it = shadow.begin(); it != shadow.end(); it++){
		for (auto it2 = it->begin(); it2 != it->end(); it2++) {
			*it2 = 0;
		}
	}

	int i = 0, j = 0;
	for (i = 0; i < board.size(); i++) {
		for (j = 0; j < board[i].size(); j++) {
			int life = 0;
			// (i-1, j-1)
			if (isLife(board, i-1, j-1)) {
				life++;
			}
			// (i-1, j)
			if (isLife(board, i-1, j)) {
				life++;
			}
			// (i-1,j+1)
			if (isLife(board, i-1, j+1)) {
				life++;
			}
			// (i, j-1)
			if (isLife(board, i, j-1)) {
				life++;
			}
			// (i, j+1)
			if (isLife(board, i, j+1)) {
				life++;
			}
			// (i+1, j-1)
			if (isLife(board, i+1, j-1)) {
				life++;
			}
			// (i+1, j)
			if (isLife(board, i+1, j)) {
				life++;
			}
			// (i+1, j+1)
			if (isLife(board, i+1, j+1)) {
				life++;
			}
			shadow[i][j] = life;
			//cout << i << ", " << j << ": " << life << endl;
		}
	}
	cout << "[" << endl;
        for (i = 0; i < board.size(); i++) {
            cout << "[";
		    for (j = 0; j < board[i].size(); j++) {
		    	if (shadow[i][j] > 3 || shadow[i][j] < 2) {
	    			board[i][j] = 0;
	    		}
	    		else if (shadow[i][j] == 3) {
	    			board[i][j] = 1;
	    		}
                cout << board[i][j];
                if (j + 1 != board[i].size()) {
                    cout << ",";
                }
		    	//cout << i << ", " << j << ": shadow->" << shadow[i][j] << ", board->" << board[i][j] << endl;
		    }
            cout << "]";
            if (i + 1 != board.size()) {
                cout << ",";
            }
            cout << endl;
	    }
        cout << "]" << endl;
}

int main()
{
	vector<vector<int>> board {
		{
			0,1,0
		}, {
			0,0,1
		}, {
			1,1,1
		}, {
			0,0,0
		}
	};
	gameOfLife(board);
	return 0;
}

