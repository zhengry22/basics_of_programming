#include<iostream>
#include<vector>
using namespace std;

vector<long long> seq; long long maxim = 0, n, m, sum=0;

long long calc(long long num) {//��⣺���ֱ�ӿ��Ƿֳ�m�Σ�ÿ�������٣�����������ѡ���������˼�����ֳ����ɶΣ�ÿ��֮�Ͳ�����p�������ּܷ��Ρ�
	//���ַ���ʹ��̰�ķ����ɣ�ԭ���������ж������ٵķ���������������ÿһ�ζ�Ӧ�Ķ�β�����ᳬ��̰�ĵ�ĩβ
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
	//ȡ�����ֵ
	for (auto e : seq) {
		sum += e;
		maxim = e > maxim ? e : maxim;
	}
	//�ҵ���һ�������mҪС��
	answer = binsearch(maxim, sum);
	cout << answer;
	return 0;
}