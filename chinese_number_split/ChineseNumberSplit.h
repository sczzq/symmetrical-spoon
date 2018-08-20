#ifndef __CHINESE_NUMBER_SPLIT__
#define __CHINESE_NUMBER_SPLIT__

#include <string>
#include <vector>
#include <map>

using namespace std;

class ChineseNumberSplit {
    public:
		ChineseNumberSplit();
		~ChineseNumberSplit();
		// split a chinese number to multi-chinese-number
		// such as, 一百一十一一百一十二, to, 一百一十一 and 一百一十二
		// 
		// base rule:
		//     1, get valid number sequence,
		//     2, split,
		//     3, small change.
    bool Split(const string &src, vector<string> &result);

	static ChineseNumberSplit * GetInstance();

    private:
    bool Init();
    bool GetNumbers(const string &src,
                                    vector<string> &numbers);

    bool IsValidUnitSeq(const vector<int> &src);
    bool GetValidUnitSeq(const vector<int> &src,
                                vector<vector<int> > &valid_seq);

    bool GetValidNumsByUnit(const vector<int> &src_ones,
                                   vector<vector<int> > &valid_unit_seq,
                                   vector<vector<int> > &valid_nums);

    bool ChineseToIndex(const string &src, vector<int> &index);

    bool GetUnit(const vector<int> &src, vector<int> &unit_seq);
    bool IndexToChinese(const vector<vector<int> > &indexs,
                               vector<string> &chinese);
    bool LeftRight(vector<vector<int> > &seqs);

    bool isInit;

    // 十,百,千,万,亿
    // 20,21,22,23,24
    map<string, int> g_unit_index;

    // 零,一,二,三,四,五,六,七,八,九,幺,两,十,百,千,万,亿
    // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11,12,20,21,22,23,24
    map<string, int> g_chinese_index;

    // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11,12,20,21,22,23,24
    // 零,一,二,三,四,五,六,七,八,九,幺,两,十,百,千,万,亿
    map<int, string> g_index_chinese;

    //map<string, int> g_digit_index;
    map<int, string> g_index_digit;

    map<int, string> g_index_unit;
};

#endif // __CHINESE_NUMBER_SPLIT__
