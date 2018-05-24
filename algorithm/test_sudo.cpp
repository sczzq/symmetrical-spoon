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

#include "sudoku.hpp"

using namespace std;

int test1()
{
	string source {"800000000"
                   "070090200" 
                   "003600000"
                   "050007000"
                   "000045700"
                   "000100030"
                   "001000068"
                   "008500010"
                   "090000400"}; 
	int m = 9, n = 9;
	sudoku sdk{source, m, n};
	sdk.init();
	sdk.solve(sdk.get_data());
	sdk.print_result();
}

int test2()
{
	string source{ "700508000"
					"040000000"
					"000030506"
					"080050360"
					"096000180"
					"010003200"
					"000000600"
					"000740001"
					"270009000"};
	int m = 9, n = 9;
	sudoku sdk{source, m, n};
	sdk.init();
	sdk.solve(sdk.get_data());
	sdk.print_result();
}

int test3()
{
	string source{ "001040"
				   "402003"
				   "000204"
				   "000000"
				   "000056"
				   "504000"};
	int m = 6, n = 6;
	sudoku sdk{source, m, n};
	sdk.init();
	sdk.solve(sdk.get_data());
	sdk.print_result();
}

int test4()
{
	string source;
	std::cin >> source;
	int m = 6, n = 6;
	sudoku sdk{source, m, n};
	sdk.init();
	sdk.solve(sdk.get_data());
	sdk.print_result();
}

int test5()
{
	string source;
	for(int i = 0; i < 9; i++){
		string tmp;
		std::cout << " line " << i << ": ";
		std::cin >> tmp;
		source += tmp;
	}
	int m = 9, n = 9;
	sudoku sdk{source, m, n};
	sdk.init();
	sdk.solve(sdk.get_data());
	sdk.print_result();
}

int test10(string source)
{
	int m = 9, n = 9;
	sudoku sdk{source, m, n};
	sdk.init();
	sdk.solve(sdk.get_data());
	sdk.print_result();
}

int test9(){
	string source {"890361450"
		"635492701"
		"014785090"
		"002016308"
		"008237549"
		"370854126"
		"953648217"
		"426179035"
		"780523064"};
	test10(source);
}

int test91(){
	string source {
		"017805029"
		"804319506"
		"539726401"
		"361472908"
		"205901637"
		"970060002"
		"750194063"
		"490238715"
		"183057294"};
	test10(source);
}

int test92(){
	string source {
		"071982546"
		"945613008"
		"260745139"
		"780426301"
		"010537802"
		"500100467"
		"897204613"
		"134869270"
		"002301980"};
	test10(source);
}

int test93(){
	string source {
		"079000001"
		"080329570"
		"350714680"
		"843105726"
		"761240895"
		"025670413"
		"690430158"
		"038561947"
		"010087362"};
	test10(source);
}

int test94(){
	string source {
		"410608000"
		"958107463"
		"627093500"
		"580070014"
		"241986375"
		"736014928"
		"804230056"
		"102845000"
		"395761042"};
	test10(source);
}

int test95(){
	string source {
		"900576214"
		"600308075"
		"510249683"
		"063824500"
		"205793461"
		"470105320"
		"006001039"
		"800637150"
		"351002746"};
	test10(source);
}

int test96(){
	string source {
		"150800476"
		"070526019"
		"980417503"
		"210940657"
		"067050901"
		"540070208"
		"031004790"
		"408035162"
		"720069384"};
	test10(source);
}

int test97(){
	string source {
		"009036741"
		"005048960"
		"000097205"
		"300960178"
		"196804050"
		"857321694"
		"408710530"
		"060403800"
		"573602419"};
	test10(source);
}

int test970(){
	string source {
		"000050200"
		"080009700"
		"004002300"
		"000490003"
		"007100080"
		"400000000"
		"910003620"
		"000000000"
		"008571000"};
	test10(source);
}

int main()
{
	test1();
//	test2();
//	test3();
	test970();
}

