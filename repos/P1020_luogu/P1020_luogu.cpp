#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<cstring>
using namespace std;

vector<long long> heights, heights2; long long answers[100001], answers2[100001], ans_ite[100001], ans_ite2[100001];


long long max_inc_length(int n) {
	if (answers[n] != 0) {
		return answers[n];
	}
	if (n == 0) {
		return 1;
	}
	else {
		long long result=1;
		for (int i = 0; i < n; i++) {
			answers[i] = max_inc_length(i);
		}
		for (int i = 0; i < n; i++) {
			if (heights[i] < heights[n]) {
				result = result > answers[i] + 1 ? result : answers[i] + 1;
			}
		}
		return result;
	}
	//cout << answers[n];
}

void biggest_sum_iterative() {
	ans_ite[0] = 1;
	for (int i = 1; i < heights.size(); i++) {
		long long ansmax = 1;
		for (int j = 0; j < i; j++) {
			if (heights[j] < heights[i]) {
				long long tmp = heights[i] > heights[j] ? 1 : 0;
				ansmax = max(ansmax, ans_ite[j] + tmp);
			}
		}
		ans_ite[i] = ansmax;
	}
}

void biggest_sum_iterative2() {
	ans_ite2[0] = 1;
	for (int i = 1; i < heights2.size(); i++) {
		long long ansmax = 1;
		for (int j = 0; j < i; j++) {
			if (heights2[j] <= heights2[i]) {
				long long tmp = heights2[i] >= heights2[j] ? 1 : 0;
				ansmax = max(ansmax, ans_ite2[j] + tmp);
			}
		}
		ans_ite2[i] = ansmax;
	}
}


long long max_inc_length2(int n) {
	if (answers2[n] != 0) {
		return answers2[n];
	}
	if (n == 0) {
		return 1;
	}
	else {
		long long result = 1;
		for (int i = 0; i < n; i++) {
			answers2[i] = max_inc_length2(i);
		}
		for (int i = 0; i < n; i++) {
			if (heights2[i] <= heights2[n]) {
				result = result > answers2[i] + 1 ? result : answers2[i] + 1;
			}
		}
		return result;
	}
}
 
int main() {
	string input; stringstream missle; string tmp;
	getline(cin, input);
	for (auto e : input)
	{	
		if (e >= '0' && e <= '9') {
			tmp = tmp + e;
		}
		else {
			int a;
			missle << tmp;
			missle >> a;
			heights.push_back(a);
			tmp = ""; missle.clear();
		}
	}
	long long a;
	missle << tmp;
	missle >> a;
	heights.push_back(a);
	tmp = ""; missle.clear();
	//dp
	for (int i = heights.size() - 1; i >= 0; i--) {
		long long a = heights[i];
		heights2.push_back(a);
	}
	long long answer1 = 0;
	//answers2[heights.size() - 1] = max_inc_length2(heights.size() - 1);
	//answers[heights.size() - 1] = max_inc_length(heights.size() - 1);
	long long answer2 = 0;
	for (int i = 0; i < heights.size(); i++) {
		answer2 = answer2 > answers[i] ? answer2 : answers[i];
		answer1 = answer1 > answers2[i] ? answer1 : answers2[i];
	}
	//cout << answer1 << endl;
	//cout<<answer2;

	biggest_sum_iterative();
	biggest_sum_iterative2();
	long long result = ans_ite[0], result2 = ans_ite2[0];
	for (int i = 1; i < heights.size(); i++) {
		result = ans_ite[i] > result ? ans_ite[i] : result;
		result2 = ans_ite2[i] > result2 ? ans_ite2[i] : result2;
	}
	cout << result2<<endl;
	cout << result;
	return 0;
}