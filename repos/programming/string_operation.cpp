#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<cstdlib>
#include<time.h>
#include"my_MATH.h"
using namespace std;

//strtok    需要在C++预处理器增加如下宏： _CRT_SECURE_NO_WARNINGS
//ssrc      待分割的字符串
//delim     分割符列表
//target    存放分割后的结果

void strsplit(string& ssrc, string& delim, vector<string>& target)
{

	char* p = strtok((char*)ssrc.data(), delim.data());
	while (p != NULL) {
		target.push_back(string(p));
		p = strtok(NULL, delim.data());
	}
}
void test_strsplit(vector<string> &to)
{
	//vector<string> dest;
	string split = "-:,";
	string st = "2022-2-18,11:30";
	strsplit(st, split, to);
	for (auto& e : to) {
		cout << e << endl;
	}
}