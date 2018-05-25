字符串操作

字符串排序
单词查找树
子字符串查找
	Knuth-Morris-Pratt子字符串查找算法
	1, 根据模式字符串设置确定有限状态机,
	2, 根据确定有限状态机进行模式匹配.

	1, 
		M = pattern.length();
		R = 256
		dfa[pattern.at(0)][0] = 1;
		for(int X = 0, j = 1; j < M; j++){
			for(int c = 0; c < R; c++)
				dfa[c][j]  = dfa[c][X];
			dfa[pattern.at(j)][j] = j + 1;
			X = dfa[pattern.at(j)][X];
		}
正则表达式

