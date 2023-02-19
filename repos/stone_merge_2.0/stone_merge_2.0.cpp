#include<iostream>
#include<cstring>
using namespace std;

long long datastore[1001][1001], stone[1001];

long long merge(int lf, int rt) {
	long long result=0;
	if (datastore[lf][rt] != -1) return datastore[lf][rt];
	if (lf == rt-1) {
		return 0;
	}
	else {
		int minimum, sum=0;
		for (int i = lf + 1; i < rt; i++) {
			datastore[lf][i] = merge(lf, i);
			datastore[i][rt] = merge(i, rt);
			if (i == lf + 1) minimum = datastore[lf][i] + datastore[i][rt];
			else minimum = minimum < datastore[lf][i] + datastore[i][rt] ? minimum : datastore[lf][i] + datastore[i][rt];
		}
		for (int i = lf; i < rt; i++) {
			sum += stone[i];
		}
		return minimum + sum;
	}
}

int main() {
	memset(datastore, -1, sizeof(long long) * 1001 * 1001);
	long long n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stone[i];
	}
	if (n == 1) return 0;
	datastore[0][n] = merge(0, n);
	cout << datastore[0][n]; return 0;

}