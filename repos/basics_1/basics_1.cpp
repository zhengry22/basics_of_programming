#include<iostream>
using namespace std;

int chick[100001], datastore[200000];

void merge_sort(int* num, int l, int r)
{
	int middle = (l + r) / 2, * tmp, lp = l, rp = middle + 1;
	//when to return 
	if (l == r)
		return;
	//first, merge the left and right part
	merge_sort(num, l, middle);
	merge_sort(num, middle + 1, r);
	//create a new array to dispose number
	tmp = new int[r - l + 1];
	int flag = 0;
	while ((lp <= middle) && (rp <= r))
	{
		if (num[lp] <= num[rp])
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
	int n, days=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> chick[i];
	}
	merge_sort(chick, 1, n);
	for (int i = 1; i <= n; i++) {
		datastore[chick[i]]++;
	}
	for (int i = 0;i<200000; i++) {
		if (datastore[i] >= 3) {
			datastore[i + 1] += datastore[i] / 3;
			datastore[i] = datastore[i] % 3;
			days += datastore[i];
		}
		else days += datastore[i];
	}
	cout << days;
	return 0;
}