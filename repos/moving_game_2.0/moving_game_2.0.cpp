#include<iostream>
#include<cstring>
using namespace std;

int numbers[50001]; int n;
int datastore[50001];

int steps(int lev) {
	if (datastore[lev] != -1) return datastore[lev];
	if (lev == n) return 0;
	if (numbers[lev] == 0) return 1000000;
	else {
		int upper = lev + numbers[lev] > n ? n : lev + numbers[lev]; 
		for (int i = lev + 1; i <= upper; i++) {
			datastore[i] = steps(i);
		}
			int minimum = 1+datastore[lev + 1];
		for (int i = lev + 1; i <= upper; i++) {
			minimum = minimum < 1 + datastore[i] ? minimum : 1+datastore[i];
		}
		return minimum;
	}
}

int main() {
	memset(datastore, -1, sizeof(int) * 50001);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> numbers[i];
	}
	int answer = steps(1);
	cout << answer;
	return 0;
}

//题解：操作类题目：下一步的原理和上一步相同，可以利用树去思考，因为树的每一个子节点下面还是树。
//身处第lev格，其可以走到lev+1到min（lev+numbers[lev+1], n）格，而实际的答案则是steps[lev]=min{1+steps[lev+1], 1+steps[lev+2], ... 1+steps[i+numbers[i]]}
//坑：用memset时提交oj需要cstring； 
//注意minimum，datastore的结果可能不是函数返回值，还需要加减一些数；
//注意题目说步数是“正”还是“非负”