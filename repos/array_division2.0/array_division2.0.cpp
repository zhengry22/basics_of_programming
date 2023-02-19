#include<iostream>
#include<vector>
using namespace std;

vector<long long> seq; long long maxim = 0, n, m, sum=0;

long long calc(long long num) {//题解：如果直接考虑分成m段，每段最大多少，将会带来困难。不妨反向思考：分成若干段，每段之和不超过p，至少能分几段。
	//其拆分方法使用贪心法即可：原因是倘若有段数更少的方法，则理论上其每一段对应的段尾都不会超过贪心的末尾
	long long sum = 0, seqs = 0;
	for (auto e : seq) {
		sum += e;
		if (sum == num) {
			seqs++;
			sum = 0;
		}
		else if (sum > num) {
			seqs++;
			sum = e;
		}
	}
	if (sum != 0)
		seqs++;
	return seqs;
}

long long binsearch(int lf, int rt) {
	if (lf == rt)return lf;
	int middle = (lf + rt) /2;
	int res = calc(middle), res2 = calc(middle + 1);
	if (res>m&&res2<=m) return middle+1;
	else if (res2 > m) {
		binsearch(middle+1, rt);
	}
	else if (res <= m) {
		binsearch(lf, middle);
	}
}



int main()
{
	long long answer;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		long long tmp;
		cin >> tmp;
		seq.push_back(tmp);
	}
	//取出最大值
	for (auto e : seq) {
		sum += e;
		maxim = e > maxim ? e : maxim;
	}
	//找到第一个结果比m要小的
	answer = binsearch(maxim, sum);
	cout << answer;
	return 0;
}