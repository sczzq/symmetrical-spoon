
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <regex.h>
#include <sys/types.h>
#include <algorithm>
#include <fstream>


using namespace std;

class Tracer {
    public:
    Tracer(const string fun): f(fun) {
        cout << "in " << f << endl;
    };
    ~Tracer() {
        cout << "leave " << f << endl;
    };
    private:
    string f;
};


// 单位个数
// 汉字数字个数
#define NUM_COUNT 12
#define NUM_COUNT_TMP 22
// 汉字数字
//{"一", "二", "三", "四", "五", "六", "七", "八", "九", "零", "幺", "两"};
//{"一", "二", "三", "四", "五", "六", "七", "八", "九", "零", "点", "十"};
// 每个汉字长度
#define ONE_CHAR_LENGTH 3

// 十,百,千,万,亿
// 20,21,22,23,24
map<string, int> g_unit_index;
// 20,21,22,23,24
// 十,百,千,万,亿
map<int, string> g_index_unit;

// 亿,万,千,百,十
string units_map = "54321";

// 零,一,幺,二,两,三,四,五,六,七,八,九,幺,两,十,百,千,万,亿
// 0, 1, 1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 11,12,20,21,22,23,24
map<string, int> g_chinese_index;

// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,20,21,22,23,24
// 零,一,二,三,四,五,六,七,八,九,幺,两,十,百,千,万,亿
map<int, string> g_index_chinese;

map<string, int> g_digit_index;
map<int, string> g_index_digit;


vector<string> g_valid_unit_seq;
vector<string> g_unit_ascend_seq;

bool ShowVector(const vector<int> &v)
{
    int i ;
    for (i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}

//一千两百三十四万五千六百七十八亿九千八百七十六万五千四百三十二
//千百十万千百十亿千百十万千百十
bool IsValidUnitSeq(const vector<int> &src)
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
        if (src[i-1] < src[i]){
            // just in 万 or 亿 could revert sequence.
            if (src[i] != yi_index && src[i] != wan_index) {
                return false;
            }
        }
    }
    return true;
}

/*
        // 两 二, index: 12, 2.
        if (src[i-1] < 20 && src[i] < 20 && src[i-i] % 10 == src[i] % 10) {
            return false;
        }
        */
bool GetValidUnitSeq(const vector<int> &src, vector<vector<int>> &valid_seq)
{
    Tracer tracer(__func__);
    int offset = 0;
    ShowVector(src);
    cout << endl;
    bool ret = false;
    for (offset = 0; offset < src.size(); ) {
        int j = 0;
        vector<int> last_sub;
        for (j = offset + 1; j <= src.size(); j++) {
            // TODO, use template compare.
            vector<int> sub_unit (src.begin() + offset, src.begin() + j);
            cout << "offset: " << offset << ", j: " << j << ", [";
            ShowVector(sub_unit);
            // check unit sequence.
            ret = IsValidUnitSeq(sub_unit);
            if (ret == true) {
                cout << "] is valid unit sequence\n";
                last_sub = sub_unit;
            }
            else {
                valid_seq.push_back(last_sub);
                last_sub.clear();
                cout << "] not a valid unit sequence.\n";
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
    int i = 0;
    for (i = 0; i < valid_seq.size(); i++) {
        cout << "valid unit: [";
        ShowVector(valid_seq[i]);
        cout << "]" << endl;
    }
    return true;
}

bool GetValidNumsByUnit(const vector<int> &src_ones,
                  vector<vector<int>> &valid_unit_seq,
                 vector<vector<int>> &valid_nums)
{
    Tracer tracer(__func__);
    {
        int i = 0, j = 0, k = 0;
        for (i = 0; i < valid_unit_seq.size(); i++) {
            vector<int> &unit_seq = valid_unit_seq[i];
            vector<int> res;
            bool lastisdigit = false;
            {
                int iii = 0;
                cout << "this unit_seq size: " << unit_seq.size() << ", content: ";
                ShowVector(unit_seq);
                cout << endl;
            }
            for (j = 0; j < unit_seq.size(); j++) {
                for ( ; k < src_ones.size(); k++) {
                    if (g_index_digit.find(src_ones[k]) != g_index_digit.end()) {
                        if (lastisdigit) {
                            valid_nums.push_back(res);
                            res.clear();
                        }
                        res.push_back(src_ones[k]);
                        cout << "1res: " << res.size() << ",content:";
                        ShowVector(res);
                        cout << endl;
                        lastisdigit = true;
                    }
                    else if(g_index_unit.find(src_ones[k]) != g_index_unit.end()) {
                        res.push_back(src_ones[k]);
                        cout << "2res: " << res.size() << ",content:";
                        ShowVector(res);
                        cout << endl;
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
                    cout << "3res: " << valid_nums[valid_nums.size()-1].size() << ",content:";
                    ShowVector(valid_nums[valid_nums.size()-1]);
                    cout << endl;
                }
            }
            k++;
        }
        if (k < src_ones.size() && last_is_zero) {
            if (valid_nums.size() > 0) {
                valid_nums[valid_nums.size()-1].push_back(src_ones[k]);
                cout << "4res: " << valid_nums[valid_nums.size()-1].size() << ",content:";
                ShowVector(valid_nums[valid_nums.size()-1]);
                cout << endl;
            }
            k++;
        }

        for ( ; k < src_ones.size(); k++ ) {
            cout << "ttttt: " << k << endl;
        }

        for (i = 0; i < valid_nums.size(); i++) {
            vector<int> &valid_num = valid_nums[i];
            cout << "valid num: ";
            ShowVector(valid_num);
            cout << endl;
        }
    }
    return true;
}

bool ChineseToIndex(const string &src, vector<int> &index)
{
    bool ret = true;
    int i = 0;
    for (i = 0; i < src.length(); i += ONE_CHAR_LENGTH) {
        string sss = src.substr(i, ONE_CHAR_LENGTH);
        if (g_chinese_index.find(sss) == g_chinese_index.end()) {
            cout << sss << ",not digits, error\n";
            ret = false;
            break;
        }
        index.push_back(g_chinese_index[sss]);
    }
    return ret;
}

// TODO, use copy_if
bool GetUnit(const vector<int> &src, vector<int> &unit_seq)
{
    int i = 0;
    for (i = 0; i < src.size(); i++) {
        if (src[i] >= 20) {
            unit_seq.push_back(src[i]);
        }
    }
    return true;
}

bool IndexToChinese(const vector<vector<int>> &indexs, vector<string> &chinese)
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
                    cout << "valid_nums[i][j] " << indexs[i][j] << " is not valid number\n"; 
                    break;
                }
            }
            chinese.push_back(num);
            cout << "valid number: " << num << endl;
        }
    }

}

bool LeftRight(vector<vector<int>> &seqs)
{
    Tracer tracer(__func__);
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
}

bool GetValidNumberMatch(const string &src, vector<string> &numbers)
{
    Tracer tracer(__func__);
    int offset = 0;
    vector<int> src_index_ones;
    cout << "src: " << src << endl;

    bool ret = ChineseToIndex(src, src_index_ones);

    vector<int> unit_seq;
    GetUnit(src_index_ones, unit_seq);

    if (unit_seq.size() < 2) {
        // has one unit.
        return true;
    }

    vector<vector<int>> valid_unit_seq;
    GetValidUnitSeq(unit_seq, valid_unit_seq);

    int i = 0, j = 0, k = 0;
    {
        cout << "src_index_ones size: " << src_index_ones.size() << endl;
        cout << "its content: [";
        ShowVector(src_index_ones);
        cout << "]" << endl;
    }

    vector<vector<int>> valid_nums;
    GetValidNumsByUnit(src_index_ones, valid_unit_seq, valid_nums);

    LeftRight(valid_nums);

    //vector<string> numbers;
    IndexToChinese(valid_nums, numbers);
    
    return ret;
}

bool InitGlobal()
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

	g_unit_ascend_seq = {"十", "百", "千", "万", "亿"};

	g_valid_unit_seq = {"万", "千", "百", "十", "亿", "千", "百", "十", "万", "千", "百", "十"};

}

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
    InitGlobal();
	vector<string> srcs; 
    bool ret = ReadSource(srcs);
    if (ret == false) {
        return 1;
    }
    int i = 0;
    for (i = 0; i < srcs.size(); i++) {
        vector<string> numbers;

        GetValidNumberMatch(srcs[i], numbers);

        cout << srcs[i] << endl;
        cout << "-------------------\n";
    }

	return 0;
}


