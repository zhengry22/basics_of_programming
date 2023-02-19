#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<cmath>
#include<numeric>
#include<cstdlib>
#include<time.h>
#include<string>
//#define zry_test 1
using namespace std;

#ifdef zry_test
void genseeds()
{
	srand(time(0));
}

void genrandnumber(int minnum, int maxnum, int num, int numperline = 10)
{
	for (int i = 0; i < num; i++)
	{
		int a = rand() % (maxnum - minnum + 1) + minnum;
		cout << a << (((i + 1) % numperline == 0) ? '\n' : ' ');
		//cout << a+rand() % (maxnum - minnum + 1) + minnum << endl;
	}
}

string genrandstring(int length) {
	string all_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string tmp;
	for (int i = 0; i < length; i++) {
		int a = rand() % all_chars.size();
		tmp.push_back(all_chars[a]);
	}
	return tmp;
}

void prepare_test() {
	genseeds();
}
#endif

int main() {
	int input;
	cin >> input;
#ifdef zry_test
	prepare_test();
	for (int i = 1; i <= input; i++) {
		string a = genrandstring(10);
		cout << a << endl;
	}
	genrandnumber(1, 100, 10);
#endif

	return 0;
}