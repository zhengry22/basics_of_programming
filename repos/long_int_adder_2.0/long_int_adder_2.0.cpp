#include<iostream>
#include<string>
using namespace std;

int main() {
	string a1,a2;
	cin >> a1>>a2;
	string add1, add2;
	if (a1.size() > a2.size()) {
		for (int i = 1; i <= a1.size() - a2.size(); i++) {
			add2.push_back('0');
		}
		add2 = add2 + a2; add1 = a1;
	}
	else {
		for (int i = 1; i <= a2.size() - a1.size(); i++) {
			add1.push_back('0');
		}
		add1 = add1 + a1; add2 = a2;
	}
	string extra,result;
	extra.resize(add1.size()+1, 0);
	result.resize(add1.size()+1, 0);
	extra[add1.size()] = 0;
	for (int i = add1.size() - 1; i >= 0; i--) {
		int tmp = (add1[i]-48) + (add2[i]-48)+(extra[i+1]);
		extra[i] = (tmp / 10);
		int tmp2 = tmp % 10;
		if (i == 0) {
			if (tmp >= 10) {
				result[0] = (tmp / 10) + 48;
				result[1] = (tmp % 10) + 48;
			}
			else {
				result[1] = tmp2 + 48;
				result.erase(result.begin());
			}
		}
		else {
			result[i + 1] = tmp2+48;
		}
	}
	cout << result;
	return 0;
}