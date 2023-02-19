#include<iostream>
using namespace std;

struct seg {
	int lf;
	int rt;
};

int sum = 0; seg segments[1001];

void merge_sort(seg* num, int l, int r)
{
	int middle = (l + r) / 2, lp = l, rp = middle + 1; seg* tmp;
	//when to return 
	if (l == r)
		return;
	//first, merge the left and right part
	merge_sort(num, l, middle);
	merge_sort(num, middle + 1, r);
	//create a new array to dispose number
	tmp = new seg[r - l + 1];
	int flag = 0;
	while ((lp <= middle) && (rp <= r))
	{
		if (num[lp].lf < num[rp].lf||(num[lp].lf == num[rp].lf&&num[lp].rt<=num[rp].rt))
		{
			tmp[flag] = num[lp];
			lp++;
		}
		else 
		{
			tmp[flag] = num[rp];
			rp++;
		}
		flag++;
	}
	if (lp <= middle)
	{
		for (int i = lp; i <= middle; i++)
		{
			tmp[flag] = num[i];
			flag++;
		}
	}
	if (rp <= r)
	{
		for (int i = rp; i <= r; i++)
		{
			tmp[flag] = num[i];
			flag++;
		}
	}
	//put the numbers in tmp into num
	for (int i = 0, j = l; i < r - l + 1; i++, j++)
	{
		num[j] = tmp[i];
	}
	delete[] tmp;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> segments[i].lf >> segments[i].rt;
	}
	merge_sort(segments, 1, n);
	int max_rt = 0;
	for (int i = 1; i <= n; i++) {
		if (i < n) {
			if (segments[i].lf < segments[i + 1].lf) {
				int tmp1 = segments[i].lf > max_rt ? segments[i].lf : max_rt;
				int tmp2 = segments[i].rt > max_rt ? segments[i].rt - tmp1 : 0;
				sum += tmp2;
				max_rt = max_rt > segments[i].rt ? max_rt : segments[i].rt;	
			}
		}
		if (i == n) {
			int tmp1 = segments[i].lf > max_rt ? segments[i].lf : max_rt;
			int tmp2 = segments[i].rt > max_rt ? segments[i].rt - tmp1 : 0;
			sum += tmp2;
		}
	}
	cout << sum;
	return 0;
}