#include<iostream>
#include<string>
using namespace std;

string before, after;	int p1, p2, p3;

bool low(char a) {
	if (a >= 'a' && a <= 'z')return true;
	else return false;
}

bool num(char a) {
	if (a >= '0' && a <= '9')return true;
	else return false;
}

char fillin(char a) {
	if (p1 == 1)return a;
	if (p1 == 2)return a - 32;
	if (p1 == 3)return '*';
}

char fill_num(char a) {
	if (p1 == 1||p1==2)return a;
	if (p1 == 3)return '*';
}

int main() {

	cin >> p1 >> p2 >> p3;
	cin >> before; 
	for (int i = 0; i < before.size(); i++) {
		if (before[i] != '-'||i==before.size()-1) {
			after.push_back(before[i]);
		}
		else {
			if (low(before[i - 1]) && low(before[i + 1])) {
				//letters
				if (before[i - 1] < before[i + 1]) {
					for (int j = 1; j < before[i + 1] - before[i - 1]; j++) {
						if (p3 == 1) {
							for (int k = 1; k <= p2; k++) {
								after.push_back(fillin(before[i - 1] + j));
							}
						}
						else if (p3 == 2) {
							for (int k = 1; k <= p2; k++) {
								after.push_back(fillin(before[i + 1] - j));
							}
						}
					}
				}
				else after.push_back(before[i]);
			}
			else if (num(before[i - 1]) && num(before[i + 1])) {
				//numbers
				if (before[i - 1] < before[i + 1]) {
					for (int j = 1; j < before[i + 1] - before[i - 1]; j++) {
						if (p3 == 1) {
							for (int k = 1; k <= p2; k++) {
								after.push_back(fill_num(before[i - 1] + j));
							}
						}
						else if (p3 == 2) {
							for (int k = 1; k <= p2; k++) {
								after.push_back(fill_num(before[i + 1] - j));
							}
						}
					}
				}
				else after.push_back(before[i]);
			}
			else after.push_back(before[i]);
		}
	}
	cout << after;
	return 0;
}