#include<iostream>
#include<string>
using namespace std;

struct clc {
	int h;
	int m;
};

int main() {
	int total=0;
	string time[4];
	for (int i = 0; i < 4; i++) {
		cin >> time[i];
	}
	int hour[4], min[4];
	for (int i = 0; i < 4; i++) {
		hour[i] = 10 * (time[i][0] - 48) + (time[i][1] - 48);
		min[i]= 10 * (time[i][3] - 48) + (time[i][4] - 48);
	}
	if (hour[2] > hour[1] || (hour[2] == hour[1] && min[2] >= min[1])) {
		cout << -1;
		return 0;
	}
	clc c1,c2;
	if (hour[0] < hour[2] || (hour[0] == hour[2] && min[0] < min[2])) {
		c1.h = hour[0];
		c1.m = min[0];
	}
	else if (hour[0] > hour[2] || (hour[0] == hour[2] && min[0] > min[2])) {
		c1.h = hour[2];
		c1.m = min[2];
	}

	if (hour[1] > hour[3] || (hour[1] == hour[3] && min[1] > min[3])) {
		c2.h = hour[1];
		c2.m = min[1];
	}
	if (hour[1] < hour[3] || (hour[1] == hour[3] && min[1] < min[3])) {
		c2.h = hour[3];
		c2.m = min[3];
	}
	total = (hour[3] - hour[2]) * 60 + min[3] - min[2] + (hour[1] - hour[0]) * 60 + min[1] - min[0];
	total -= ((c2.h - c1.h) * 60 + c2.m - c1.m);
	if (total < 0) {
		total = total * (-1);
	}
	cout << total;
	return 0;
}