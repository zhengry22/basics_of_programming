#include<iostream>
using namespace std;

struct seg {
	int lf;
	int rt;
};

seg segs[25001];	int n, m;
void merge_sort(seg* num, int l, int r)
{
	int middle = (l + r) / 2; seg* tmp; int lp = l, rp = middle + 1;
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
		if (num[lp].lf <= num[rp].lf)
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


int calc() {
	if (segs[0].lf != 1)return -1;
	int k = 0, max_rt = 0, next_rt = 0, cnt = 0;
	//先考虑起始点为1的线段
	while (k<n&&segs[k].lf == 1) {
		if (segs[k].rt > max_rt) {
			max_rt = segs[k].rt;
			k++;
		}
	}
	next_rt = max_rt; cnt++;
	if (k >= n) {
		return max_rt >= m ? 1 : -1;
	}
	for (int i = k; i < n; i++) {
		if (max_rt >= m) return cnt;
		if (segs[i].lf <= max_rt) {
			next_rt = next_rt > segs[i].rt ? next_rt : segs[i].rt;
		}
		else return -1;
		if (i!=n-1&&segs[i + 1].lf > max_rt) {
			max_rt = next_rt;
			cnt++;
		}
	}
	if (next_rt >= m) { cnt++; return cnt; }
	else return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> segs[i].lf >> segs[i].rt;
	}
	merge_sort(segs, 0, n - 1);
	int answer=calc();
	cout << answer;
	return 0;
}