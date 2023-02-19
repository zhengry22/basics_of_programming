#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<time.h>
#include<algorithm>
using namespace std;
#define M -50000000

long long seq[2001];
long long answer[2001];
long long ans_ite[2001];

int numcnt; int n;
int number[2001];
int datastore[2001];

//产生随机数种子
void genseeds()
{
	srand(time(0));
}

//产生随机数
//minnum最小值
//maxnum最大值
//num数量
//numperline每行几个数
void genrandnumber(int minnum, int maxnum, int num, int numperline = 10)
{
	genseeds();
	for (int i = 0; i < num; i++)
		cout << rand() % (maxnum - minnum + 1) + minnum << (((i + 1) % numperline == 0) ? '\n' : ' ');
}

int logic(bool x, bool y, bool z, bool q)
{
	bool a[4];
	int truenum = 0;
	a[0] = x;
	a[1] = !y;
	a[2] = z;
	a[3] = !q;
	for (int i = 0; i < 4; i++)
	{
		if (a[i] == true)
			truenum++;
	}
	return truenum;

}

void testlogic()
{
	char c[4];
	char testc[4] = { 'a','b','c','d' };
	for (int i = 0; i < 4; i++)
	{

		cin >> c[i];
		c[i] = tolower(c[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		if (logic(testc[i] == c[0], testc[i] == c[1], testc[i] == c[2], testc[i] == c[3]) == 2)
			cout << testc[i];
	}
}


int maxnum(int pos)
{
	int i;
	bool found = false;
	int retval = -0x7fffff;
	int maxval = -200000;
	if (datastore[pos] != 0xffffffff)
		return datastore[pos];
	if (pos == numcnt - 1)
		return number[pos];
	for (i = pos + 1; i < numcnt; i++)
	{
		if (number[i] > number[pos])
		{
			//datastore[i+1][number[i]]=
			datastore[i] = retval = maxnum(i);
			if (retval > maxval)
				maxval = retval;
		}
	}
	return max(maxval + number[pos], number[pos]);

}

long long judge(long long a, long long b) {
	if (a > b) return a;
	else return 0;
}

long long biggest_sum(int n) {
	if (answer[n] > -50000000) {
		return answer[n];
	}
	else {
		if (n == 1) return seq[n];
		else {
			long long maximum;
			for (int i = 1; i < n; i++) {
				answer[i] = biggest_sum(i);
			}
			maximum = seq[n];
			for (int i = 1; i < n; i++) {
				if (seq[i] < seq[n]) {
					int tmp = answer[i] + seq[n];
					if (tmp > maximum) {
						maximum = tmp;
					}
				}
			}
			return maximum;
		}
	}
}

void biggest_sum_iterative() {
	ans_ite[1] = seq[1];
	for (int i = 2; i <= n; i++) {
		long long ansmax = seq[i];
		for (int j = 1; j < i; j++) {
			if (seq[j] < seq[i]) {
				int tmp = seq[i] > seq[j] ? seq[i] : 0;
				ansmax = max(ansmax, ans_ite[j] + tmp);
			}
		}
		ans_ite[i] = ansmax;
	}
}

int main() {

	int retval;
	int maxval = -200000;
	genseeds();
	memset(answer, M, sizeof(long long) * 2001);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		seq[i]= rand()%200000-200000;
	}
	answer[n] = biggest_sum(n);
	long long maximum = M;
	for (int i = 1; i <= n; i++) {
		maximum = (answer[i] > maximum) ? answer[i] : maximum;
	}



	memset(datastore, 0xff, sizeof(datastore));
	numcnt=n;
	for (int i = 0; i < numcnt; i++)
		number[i]=seq[i];
	for (int i = 0; i < numcnt; i++)
	{
		retval = maxnum(i);
		if (retval > maxval)
			maxval = retval;
	}
	cout << maxval<<endl;

	cout << maximum<<endl;
	//cout << maxval;
	biggest_sum_iterative();
	long long result = ans_ite[1];
	for (int i = 2; i <= n; i++) {
		result = ans_ite[i] > result ? ans_ite[i] : result;
	}
	cout << result;
	return 0;


}