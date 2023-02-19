#include<iostream>
using namespace std;

int num[100000];
int num2[100000];

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void merge_sort(int* p, int n)
{
	if (n <= 1)
		return;
	int l = n / 2, r = n - n / 2;
	merge_sort(p, l);
	merge_sort(p + l, r);
	int* pn = new int[n];
	int i = 0, j = l, k = 0;
	while (i < l && j < n)
	{
		if (p[i] > p[j])
			pn[k++] = p[j++];
		else
			pn[k++] = p[i++];
	}
	for (; i < l; i++)
		pn[k++] = p[i];
	for (; j < n; j++)
		pn[k++] = p[j];
	for (int i = 0; i < n; i++)
		p[i] = pn[i];
	delete[] pn;
}
/*void quick_sort(int* p, int n)
{
	if (n <= 1)
		return;
	int t = p[n - 1], l = 0, r = n - 2;
	do {
		for (; r >= l; l++)
			if (p[l] > t)
				break;
		for (; r >= l; r--)
			if (p[r] < t)
				break;
		if (r >= l)
			swap(&p[l], &p[r]);
	} while (r >= l);
	swap(&p[l], &p[n - 1]);
	quick_sort(&p[0], l);
	quick_sort(&p[l + 1], n - l - 1);
}*/




int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	//mergesort num[0]-num[n-1]
	merge_sort(num, n);
	for (int i = 0; i < n; i++)
		cout << num[i];
	/*num2[0] = num[0];
	int place = 1,n2=n;
	for (int i = 1; i < n; i++)
	{
		if (num[i] != num[i - 1])
		{
			num2[place] = num[i];
			place++;
		}
		else
		{
			n2--;
		}
	}
	cout << n2 << endl;
	for (int i = 0; i < n2; i++)
		cout << num2[i]<<' ';
	return 0;*/
}