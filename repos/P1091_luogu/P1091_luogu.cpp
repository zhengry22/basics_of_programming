#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> queue, queue_back; int ans_ite[101], ans_ite2[101];

void biggest_sum_iterative() {
	ans_ite[0] = 1;
	for (int i = 1; i < queue.size(); i++) {
		long long ansmax = 1;
		for (int j = 0; j < i; j++) {
			if (queue[j] < queue[i]) {
				long long tmp = queue[i] > queue[j] ? 1 : 0;
				ansmax = max(ansmax, ans_ite[j] + tmp);
			}
		}
		ans_ite[i] = ansmax;
	}
}

void biggest_sum_iterative2() {
	ans_ite2[0] = 1;
	for (int i = 1; i < queue_back.size(); i++) {
		long long ansmax = 1;
		for (int j = 0; j < i; j++) {
			if (queue_back[j] < queue_back[i]) {
				long long tmp = queue_back[i] > queue_back[j] ? 1 : 0;
				ansmax = max(ansmax, ans_ite2[j] + tmp);
			}
		}
		ans_ite2[i] = ansmax;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;
		queue.push_back(h);
	}
	for (int i = queue.size() - 1; i >= 0; i--) {
		int h;
		h = queue[i];
		queue_back.push_back(h);
	}
	biggest_sum_iterative();
	biggest_sum_iterative2();
	int result = 1;
	for (int i = 0, j=queue.size()-1; i < queue.size(),j>=0; i++,j--) {
		if (ans_ite[i] == 1){// || ans_ite2[j] == 1) {
			continue;
		}
		result = max(result, ans_ite[i] + ans_ite2[j] - 1);
	}
	cout << n - result;
	return 0;
}