
#include "ChineseNumberSplit.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

// 每个汉字长度
#define ONE_CHAR_LENGTH 3

using namespace std;

//using std::map;
//using std::string;
//using std::vector;

//bool ChineseNumberSplit::isInit = false;
//map<string, int> ChineseNumberSplit::g_unit_index;
//map<string, int> ChineseNumberSplit::g_chinese_index;
//map<int, string> ChineseNumberSplit::g_index_chinese;
//map<string, int> ChineseNumberSplit::g_digit_index;
//map<int, string> ChineseNumberSplit::g_index_digit;
//map<int, string> ChineseNumberSplit::g_index_unit;

ChineseNumberSplit *chineseNumberSplit = NULL;


ChineseNumberSplit * ChineseNumberSplit::GetInstance()
{
	if (chineseNumberSplit == NULL) {
		chineseNumberSplit = new ChineseNumberSplit();
	}

	return chineseNumberSplit;
}

ChineseNumberSplit::ChineseNumberSplit()
{
	Init();
}

ChineseNumberSplit::~ChineseNumberSplit()
{
}

bool ChineseNumberSplit::Split(const string &src, vector<string> &numbers)
{
    return GetNumbers(src, numbers);
}

bool ChineseNumberSplit::Init()
{
	g_chinese_index["零"] = 0;
	g_chinese_index["一"] = 1;
	g_chinese_index["二"] = 2;
	g_chinese_index["三"] = 3;
	g_chinese_index["四"] = 4;
	g_chinese_index["五"] = 5;
	g_chinese_index["六"] = 6;
	g_chinese_index["七"] = 7;
	g_chinese_index["八"] = 8;
	g_chinese_index["九"] = 9;
	g_chinese_index["幺"] = 11;
	g_chinese_index["两"] = 12;
	g_chinese_index["十"] = 20;
	g_chinese_index["百"] = 21;
	g_chinese_index["千"] = 22;
	g_chinese_index["万"] = 23;
	g_chinese_index["亿"] = 24;

	g_index_chinese[0] = "零";
	g_index_chinese[1] = "一";
	g_index_chinese[2] = "二";
	g_index_chinese[3] = "三";
	g_index_chinese[4] = "四";
	g_index_chinese[5] = "五";
	g_index_chinese[6] = "六";
	g_index_chinese[7] = "七";
	g_index_chinese[8] = "八";
	g_index_chinese[9] = "九";
	g_index_chinese[11] = "幺";
	g_index_chinese[12] = "两";

	g_index_chinese[20] = "十";
	g_index_chinese[21] = "百";
	g_index_chinese[22] = "千";
	g_index_chinese[23] = "万";
	g_index_chinese[24] = "亿";

	/*
	g_digit_index["零"] = 0;
	g_digit_index["一"] = 1;
	g_digit_index["二"] = 2;
	g_digit_index["三"] = 3;
	g_digit_index["四"] = 4;
	g_digit_index["五"] = 5;
	g_digit_index["六"] = 6;
	g_digit_index["七"] = 7;
	g_digit_index["八"] = 8;
	g_digit_index["九"] = 9;
	g_digit_index["幺"] = 11;
	g_digit_index["两"] = 12;
	*/

	g_index_digit[0] = "零";
	g_index_digit[1] = "一";
	g_index_digit[2] = "二";
	g_index_digit[3] = "三";
	g_index_digit[4] = "四";
	g_index_digit[5] = "五";
	g_index_digit[6] = "六";
	g_index_digit[7] = "七";
	g_index_digit[8] = "八";
	g_index_digit[9] = "九";
	g_index_digit[11] = "幺";
	g_index_digit[12] = "两";

	g_unit_index["十"] = 20;
	g_unit_index["百"] = 21;
	g_unit_index["千"] = 22;
	g_unit_index["万"] = 23;
	g_unit_index["亿"] = 24;

	g_index_unit[20] = "十";
	g_index_unit[21] = "百";
	g_index_unit[22] = "千";
	g_index_unit[23] = "万";
	g_index_unit[24] = "亿";

	return true;
}

/*
bool ShowVector(const vector<int> &v)
{
    int i ;
    for (i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}
*/

//一千两百三十四万五千六百七十八亿九千八百七十六万五千四百三十二
//千百十万千百十亿千百十万千百十
// reture result to check is or not valid unit seq. inner use.
//
bool ChineseNumberSplit::IsValidUnitSeq(const vector<int> &src)
{
    int i = 0;
    bool descend = true;
    int yi_index = g_unit_index["亿"];
    int wan_index = g_unit_index["万"];
    if (src.size() < 2){
        return true;
    }
    // at most one 亿 in valid unit sequence.
    if (count(src.begin(), src.end(), yi_index) > 1) {
        return false;
    }
    vector<int>::const_iterator yi_it = find(src.begin(), src.end(), yi_index);
    // at most two 万 in valid unit sequence.
    // at most one 万 before 亿 in valid unit sequence.
    if (count(src.begin(), yi_it, wan_index) > 1) {
        return false;
    }
    // at most one 万 after 亿 in valid unit sequence.
    if (count(yi_it, src.end(), wan_index) > 1) {
        return false;
    }
    int last_max = src[0];
    int yi_count = 0, wan_count = 0;
    for (i = 1; i < src.size(); i++) {
        // two continual same is invalid.
        if (src[i-1] == src[i]) {
            return false;
        }
        // 两 二, index: 12, 2.
        // 幺 一, index: 11, 1.
        if (src[i-1] < 20 && src[i] < 20 && src[i-i] % 10 == src[i] % 10) {
            return false;
        }
        if (src[i-1] < src[i]){
            // just in 万 or 亿 could revert sequence.
            if (src[i] != yi_index && src[i] != wan_index) {
                return false;
            }
        }
    }
    return true;
}

// return always true.
bool ChineseNumberSplit::GetValidUnitSeq(const vector<int> &src, vector<vector<int> > &valid_seq)
{
    int offset = 0;
    bool ret = false;
    for (offset = 0; offset < src.size(); ) {
        int j = 0;
        vector<int> last_sub;
        for (j = offset + 1; j <= src.size(); j++) {
            // TODO, use template compare.
            vector<int> sub_unit (src.begin() + offset, src.begin() + j);
            // check unit sequence.
            ret = IsValidUnitSeq(sub_unit);
            if (ret == true) {
                last_sub = sub_unit;
            }
            else {
                valid_seq.push_back(last_sub);
                last_sub.clear();
                break;
            }
        }
        if (last_sub.size() != 0) {
            valid_seq.push_back(last_sub);
            last_sub.clear();
        }
        if (offset+1 == src.size()) {
            break;
        }
        offset = j - 1;
    }
    return true;
}

// return always return true.
bool ChineseNumberSplit::GetValidNumsByUnit(const vector<int> &src_ones,
                  vector<vector<int> > &valid_unit_seq,
                 vector<vector<int> > &valid_nums)
{
	int i = 0, j = 0, k = 0;
	for (i = 0; i < valid_unit_seq.size(); i++) {
		vector<int> &unit_seq = valid_unit_seq[i];
		vector<int> res;
		bool lastisdigit = false;
		for (j = 0; j < unit_seq.size(); j++) {
			for ( ; k < src_ones.size(); k++) {
				if (g_index_digit.find(src_ones[k]) != g_index_digit.end()) {
					if (lastisdigit) {
						valid_nums.push_back(res);
						res.clear();
					}
					res.push_back(src_ones[k]);
					lastisdigit = true;
				}
				else if(g_index_unit.find(src_ones[k]) != g_index_unit.end()) {
					res.push_back(src_ones[k]);
					lastisdigit = false;
					j++;
					if (j >= unit_seq.size()) {
						k++;
						break;
					}
				}
			}
		}
		if (res.size() > 0) {
			valid_nums.push_back(res);
		} 
	}
	bool last_is_zero = false;
	if (k < src_ones.size()) {
		if (g_index_digit.find(src_ones[k]) != g_index_digit.end()) {
			if (valid_nums.size() > 0) {
				valid_nums[valid_nums.size()-1].push_back(src_ones[k]);
				if (src_ones[k] == 0) {
					last_is_zero = true;
				}
			}
		}
		k++;
	}
	if (k < src_ones.size() && last_is_zero) {
		if (valid_nums.size() > 0) {
			valid_nums[valid_nums.size()-1].push_back(src_ones[k]);
		}
		k++;
    }

	// the last numbers which has no unit.
	for ( ; k < src_ones.size(); k++ ) {
		vector<int> temp;
		temp.push_back(src_ones[k]);
		valid_nums.push_back(temp);
	}

    return true;
}

// return
//      if has non-chinese-number, return false
//      if all is chinese-number, return true
bool ChineseNumberSplit::ChineseToIndex(const string &src,
                                        vector<int> &index)
{
    int i = 0;
    for (i = 0; i < src.length(); i += ONE_CHAR_LENGTH) {
        string sss = src.substr(i, ONE_CHAR_LENGTH);
        if (g_chinese_index.find(sss) == g_chinese_index.end()) {
            return false;
        }
		index.push_back(g_chinese_index[sss]);
    }
    return true;
}

// TODO, use copy_if
// return always return true
bool ChineseNumberSplit::GetUnit(const vector<int> &src, vector<int> &unit_seq)
{
    int i = 0;
    for (i = 0; i < src.size(); i++) {
        if (src[i] >= 20) {
            unit_seq.push_back(src[i]);
        }
    }
    return true;
}

// return always return true
bool ChineseNumberSplit::IndexToChinese(const vector<vector<int> > &indexs, vector<string> &chinese)
{
    int i = 0, j = 0;
    {
        for (i = 0; i < indexs.size(); i++) {
            string num;
            for (j = 0; j < indexs[i].size(); j++) {
                if (g_index_chinese.find(indexs[i][j]) != g_index_chinese.end()){
                    num += g_index_chinese[indexs[i][j]];
                }
                else{
                    break;
                }
            }
            chinese.push_back(num);
        }
    }
    return true;
}

// return always return true
bool ChineseNumberSplit::LeftRight(vector<vector<int> > &seqs)
{
    int i = 1, j = 0;
    for (i = 1; i < seqs.size(); i++) {
        vector<int> &seq_1 = seqs[i-1];
        vector<int> &seq_2 = seqs[i];

        // move from this to last.
        // the last of last is digit
        if (g_index_digit.find(seq_1[seq_1.size()-1]) != g_index_digit.end()) {
            // add digit to last, last one is 0.
            // 一百零, 一
            if (seq_2.size() == 1 && seq_1[seq_1.size()-1] == 0) {
                seq_1.push_back(seq_2[0]);
                seqs.erase(seqs.begin() + i);
                i--;
            }
        }
        // move from this to last.
        // the last of last is unit
        else if (g_index_unit.find(seq_1[seq_1.size()-1]) != g_index_unit.end()) {
            // add digit to last.
            if (seq_2.size() == 1 && g_index_digit.find(seq_2[0]) != g_index_digit.end()) {
                seq_1.push_back(seq_2[0]);
                seqs.erase(seqs.begin() + i);
                i--;
            }
        }

        // move from last to this.
        // the first of this is unit.
        if (g_index_unit.find(seq_2[0]) != g_index_unit.end()) {
            int i = seq_1.size() - 1;
            for ( i; i > 0; i-- ){
                if (g_index_unit.find(seq_1[i]) != g_index_unit.end() && 
                    seq_1[i] < seq_2[0]){
                    // insert the unit.
                    seq_2.insert(seq_2.begin(), seq_1[i]);
                }
                else{
                    break;
                }
            }
            // insert the digit.
            if (g_index_unit.find(seq_1[i]) == g_index_unit.end()){
                seq_2.insert(seq_2.begin(), seq_1[i]);
                i--;
            }
            seq_1.erase(seq_1.begin() + i + 1, seq_1.end());
        }
    }
    return true;
}

// return 
//      true    yes split.
//      false   no split.
// parameter
//      should be all chinese number.
bool ChineseNumberSplit::GetNumbers(const string &src, vector<string> &numbers)
{
    int offset = 0;
    bool ret = true;

    vector<int> src_index_ones;

    ret = ChineseToIndex(src, src_index_ones);
    if (!ret) {
        return false;
    }

    vector<int> unit_seq;
    GetUnit(src_index_ones, unit_seq);

    if (unit_seq.size() < 2) {
        // has one unit.
        return false;
    }

    vector<vector<int> > valid_unit_seq;
    GetValidUnitSeq(unit_seq, valid_unit_seq);

    vector<vector<int> > valid_nums;
    GetValidNumsByUnit(src_index_ones, valid_unit_seq, valid_nums);

    LeftRight(valid_nums);
    IndexToChinese(valid_nums, numbers);

    return true;
}

/*
*/
bool ReadSource(vector<string> &src)
{
    string file = "chinese_num.txt";
    ifstream infile(file.c_str());
    if (!infile){
        cout << "file open error, " << file << endl;
        return false;
    }
    string line;
    while (getline(infile, line)) {
        src.push_back(line);
    }
    infile.close();
    return true;
}

int main()
{
    //InitGlobal();
	vector<string> srcs; 
    bool ret = ReadSource(srcs);
    if (ret == false) {
        return 1;
    }
    int i = 0;
    for (i = 0; i < srcs.size(); i++) {
        vector<string> numbers;

        ChineseNumberSplit::GetInstance()->Split(srcs[i], numbers);

        cout << "src: " << srcs[i] << endl;
        int j = 0;
        for (j = 0; j < numbers.size(); j++) {
            cout << "number: " << numbers[j] << endl;
        }
        cout << "-------------------\n";
    }

	return 0;
}


