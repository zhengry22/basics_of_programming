#include<iostream>
using namespace std;

int stock[100001];

int main() {
	int n, money=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stock[i];
	}
	if (stock[2] > stock[1]) {
		money -= stock[1];
	}
	for (int i = 2; i <= n-1; i++) {
		
		if (stock[i] > stock[i - 1] && stock[i] > stock[i + 1]) {
			money += stock[i];
		}
		if (stock[i] < stock[i - 1] && stock[i] < stock[i + 1]) {
			money -= stock[i];
		}
	}
	if (stock[n] > stock[n - 1]) {
		money += stock[n];
	}
	cout << money;
	return 0;

}

//题解：什么时候买股票：在价格震荡到波谷的时候（极小值）；什么时候卖：波峰（极大值）