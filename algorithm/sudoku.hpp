/*************************************************************************
	> File Name: sudoku.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 20 Aug 2017 06:36:50 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <utility>

#ifndef __SUDO_KU_HPP_
#define __SUDO_KU_HPP_
/*
 * 数独游戏的解法，
 * 4*4，6*6，9*9
 * 4*4，小方格是2*2
 * 6*6，小方格是2*3
 * 9*9，小方格是3*3
 *
 */

using namespace std;
class sudoku{
	public:
		sudoku(string s, int mm, int nn)
			: source{s}, m{mm}, n{nn} {
				if(m == n){
					if(s.length() == m*n ){
						isvalid = 0;
						for(int i=0; i < m; i++){
							_pv |= 1<<i;
						}
//						std::cout << _pv << std::endl;
						if(m == 6 && n == 6){
							bm = 2;
							bn = 3;
						}
						if(m == 4 && n == 4){
							bm = bn = 2;
						}
//						std::cout << "m: " << m << ", n: " << n << std::endl;
//						std::cout << "bm: " << bm << ", bn: " << bn << std::endl;
					}
				}
			}

		~sudoku() { }

		vector<vector<int>> &get_data(){
			return _data;
		}

		int init(){
			if(isvalid == 1)
				return -1;
			for(int i = 0; i < m; i++){
				vector<int> dv;
				for(int j = 0; j < n; j++){
					int v = source.at(i*m+j) - '0';
					if(v == 0)
						dv.push_back(_pv);
					else
						dv.push_back(1<<(v-1));
				}
				_data.push_back(dv);
			}
			__data = _data;
			print(_data);
			return 0;
		}

		int solve(vector<vector<int>> &data){
			if(isvalid == 1)
				return -1;
			analyse(data);
			int result = check(data);
//			std::cout << result << std::endl;
			if(result == 1){
				pair<int, int> position = small_position(data);
				int pv = data[position.first][position.second];
				int pvcount = bit_count(pv);
				for(int i=0; i < pvcount; i++){
					int test_v = 1 << lowest_bit(pv);
					pv ^= test_v;
					vector<vector<int>> copy = data;
					copy[position.first][position.second] = test_v;
					solve(copy);
					results++;
				}
			} else if(result == 0){
				std::cout << "--------------第" << (++i) << "个答案---- after " << results << " times resolve----------" << std::endl;
				print(data);
				print_inverse(data);
			}
		}

		pair<int, int> small_position(vector<vector<int>> &data){
			int pi = -1, pj = -1;
			int smallcount  = m+1;
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
					int bitcount = bit_count(data[i][j]);
					if(bitcount == 2)
						return make_pair(i, j);
					else if(bitcount != 1){
						if(smallcount > bitcount){
							smallcount = bitcount;
							pi = i; pj = j;
						}
					}
				}
			}
			return make_pair(pi, pj);
		}

		int check(vector<vector<int>> &data){
//			print(data);
//			print_raw(data);
			for(int i = 0; i < m; i++){
				int row = 0;
				int col = 0;
				int block = 0;
				for(int j = 0; j < n; j++){
					if(bit_count(data[i][j]) > 1){
						return 1;
					}
					row |= data[i][j];
					col |= data[j][i];
				}
				for(int  h = i / bn * bn; h < i / bn * bn + bn; ++h){
					for(int l = i % bm * bm; l < i % bm * bm + bm; ++l)
						block |= data[l][h];
				}
				if(row != _pv || col != _pv || block != _pv){
					return -1;
				}
			}
			return 0;
		}

		int analyse(vector<vector<int>> &data){
			bool changed = false;
			changed = reduce(data);
			if(changed){
				analyse(data);
			}
		}

		bool reduce(vector<vector<int>> &data){
			bool changed = false;
			for(int i = 0; i < m; ++i){
				for(int j = 0; j < n; ++j){
					if(bit_count(data[i][j]) != 1){
						if(set_maybe(data, i, j)){
							changed = true;
						}
					}
				}
			}
			return changed;
		}

		bool set_maybe(vector<vector<int>> &data, int mm, int nn){
			if(bit_count(data[mm][nn]) == 1)
				return false;
			int row = 0;
			int col = 0;
			int block = 0;
			for(int i = 0; i < m; ++i){
				if(bit_count(data[mm][i]) == 1){
					row += data[mm][i];
				}
				if(bit_count(data[i][nn]) == 1){
					col += data[i][nn];
				}
			}
			for(int i = mm / bm * bm; i < mm / bm * bm + bm; ++i){
				for(int j = nn / bn * bn; j < nn / bn * bn + bn; ++j){
					if(bit_count(data[i][j]) == 1){
						block += data[i][j];
					}
				}
			}

			int have = row | col | block;
			int left = _pv ^ have;
			return try_reduce(data, mm, nn, left);
		}

		bool try_reduce(vector<vector<int>> &data, int mm, int nn, int v){
			int old = data[mm][nn];
			data[mm][nn] = old & v;
			return data[mm][nn] != old;
		}

		void print_raw(vector<vector<int>> &data){
			std::cout << "---------------------------------------" << std::endl;
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
					int v = data[i][j];
					std::cout << v << " " ;
				}
				std::cout << std::endl;
			}
			std::cout << "---------------------------------------" << std::endl;
		}

		void print_inverse(vector<vector<int>> &data){
			std::cout << "-----------inverse----------------------------" << std::endl;
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
					int v = get_v(__data[i][j]);
//					std::cout << "(" << v << ")";
					if(v == -1){
						std::cout << get_v(data[i][j]) << " " ;
					} else {
						std::cout << "_ " ;
					}
				}
				std::cout << std::endl;
			}
			std::cout << "---------------------------------------" << std::endl;
		}

		void print(vector<vector<int>> &data){
			std::cout << "---------------------------------------" << std::endl;
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
					int v = get_v(data[i][j]);
					if(v != -1){
						std::cout << v << " " ;
					} else {
						std::cout << "_ " ;
					}
				}
				std::cout << std::endl;
			}
			std::cout << "---------------------------------------" << std::endl;
		}

		int get_v(int v){
			switch(v){
				case 1:
					return 1;
				case 2:
					return 2;
				case 4:
					return 3;
				case 8:
					return 4;
				case 16:
					return 5;
				case 32:
					return 6;
				case 64:
					return 7;
				case 128:
					return 8;
				case 256:
					return 9;
				default:
					break;
			}
			return -1;
		}

		int print_result()
		{
			std::cout << "resolved times: " << results << std::endl;
		}


		int bit_count(int c){
			int count = 0;
			for(int i = 0; i < m; i++)
				if(c & 1<<i)
					++count;
			return count;
		}

		int lowest_bit(int c){
			for(int i = 0; i < m; i++)
				if(c & 1<<i)
					return i;
		}
	private:
		string source;
		vector<vector<int>> _data;
		vector<vector<int>> __data;
		int results = 1;
		int _pv = 0;
		int m = 9; // 行  4  6  9
		int n = 9; // 列  4  6  9
		int bm = 3; // 块中的行
		int bn = 3; // 块中的列
		int i = 0;
		int isvalid = 1;
};

#endif
