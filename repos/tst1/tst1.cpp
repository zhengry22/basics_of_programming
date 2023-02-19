#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	bool p[10001]; int sign[10001];
	memset(p, false, sizeof(bool) * 10001);
	for (int i = 1; i <= m; i++) {
		cin >> sign[i];
	}
	for (int i = 1; i <= m; i++) {
		p[sign[i]] = true;
	}
	int flag = 2;
	for (int i = 1; i <= n; i++) {
		if (!p[i]) {
			flag--;
		}
		if (flag == 1&&!p[i]) {
			cout << i;
		}
		if (flag <= 0&&!p[i]) {
			cout << ' ' << i;
		}
	}
	if (flag == 2) {
		cout << "ALL";
	}
	return 0;
}