#include<iostream>
#include<string>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	if (str1.size() != str2.size()) { cout << 1; return 0; }
	else {
		if (str1 == str2) { cout << 2; return 0; }
		else {
			string str11, str22;
			for (int i = 0; i < str1.size(); i++) {
				int tmp1 = (int)str1[i], tmp2 = (int)str2[i];
				str11.push_back(toupper(tmp1)), str22.push_back(toupper(tmp2));
			}
			if (str11 == str22) { cout << 3; return 0; }
			else { cout << 4; return 0; }
		}
	}
}