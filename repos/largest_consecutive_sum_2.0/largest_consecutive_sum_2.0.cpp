#include<iostream>
using namespace std;

int datastore[50001];
int numbers[50001], store_sign[50001];

int calc(int n) {
	if (store_sign[n] != 0) return datastore[n];
	if (n == 1) return numbers[1];
	else {
		datastore[n - 1] = calc(n - 1);
		store_sign[n - 1] = 1;
		return datastore[n - 1] > 0 ? datastore[n - 1] + numbers[n] : numbers[n];
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> numbers[i];
	}
	datastore[n] = calc(n);
	int result = datastore[1];
	for (int i = 1; i <= n; i++) {
		result = result > datastore[i] ? result : datastore[i];
	}
	cout << result;
	return 0;
}