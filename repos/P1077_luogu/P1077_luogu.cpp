#include<iostream>
#include<vector>
#include<cstring>
#define mod 1000007
using namespace std;

long long datastore[101][101][101]; long long n, m;
vector<long long> limits;

long long min(long long a, long long b) {
	return a > b ? b : a;
}

long long arrange(long long length, long long kind, long long num) {
	if (datastore[length][kind][num] != -1)return datastore[length][kind][num];
	else {
		if (kind == 0) {
			if (length != num)return 0;
			else return 1;
		}
		else {
			if (length < num)return 0;
			else if (length == num)return 1;
			else {
				long long sum = 0;
				for (int i = 0; i <= min(limits[kind-1],length-num); i++) {
					datastore[length - num][kind - 1][i] = arrange(length - num, kind - 1, i)%mod;
					sum += datastore[length - num][kind - 1][i];
					sum = sum % mod;
				}
				return sum%mod;
			}
		}
		
	}
}

int main() {
	cin >> n >> m;
	memset(datastore, -1, sizeof(long long) * 101 * 101 * 101);
	for (long long i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		limits.push_back(tmp);
	}
	for (int i = 0; i <= limits[n - 1]; i++) {
		datastore[m][n - 1][i] = arrange(m, n - 1, i);
	}
	long long answer = 0;
	for (int i = 0; i <= limits[n - 1]; i++) {
		answer = answer+datastore[m][n - 1][i];
	}
	long long result = answer % mod;
	cout << result;
	return 0;
}