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

//strtok    ��Ҫ��C++Ԥ�������������º꣺ _CRT_SECURE_NO_WARNINGS
//ssrc      ���ָ���ַ���
//delim     �ָ���б�
//target    ��ŷָ��Ľ��

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