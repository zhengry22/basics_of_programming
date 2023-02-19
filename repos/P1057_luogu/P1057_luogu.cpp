#include<iostream>
#include<cstring>
using namespace std;

int n, m;

long long datastore[31][31];

long long next(long long num) {
	if (num == n)return 1;
	else return num + 1;
}

long long prev(long long num) {
	if (num == 1)return n;
	else return num - 1;
}

long long pass(long long times, long long num) {
	if (datastore[times][num] != -1)return datastore[times][num];
	else {
		if (times == 1) {
			if (num != next(1) && num != prev(1))return 0;
			else return 1;
		}
		else {
			long long tmp1 = prev(num), tmp2 = next(num);
			datastore[times - 1][tmp1] = pass(times - 1, tmp1);
			datastore[times - 1][tmp2] = pass(times - 1, tmp2);
			//cout << times - 1 << ' ' << tmp1 << datastore[times - 1][tmp1] << endl;
			//cout << times - 1 << ' ' << tmp2 << datastore[times - 1][tmp2] << endl;
			return datastore[times - 1][tmp1] + datastore[times - 1][tmp2];
		}
	}
}

int main() {
	cin >> n >> m;
	/*for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			datastore[i][j] = -1;
		}
	}*/
//	memset(datastore, -1, sizeof(int) * 31 * 31); why not?
	datastore[m][1] = pass(m, 1);
	cout << datastore[m][1]; return 0;
}