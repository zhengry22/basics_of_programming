#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<numeric>
#include<cstdlib>
#include<time.h>
#include"my_MATH.h"
#define A 1000000007
using namespace std;

int test[100000];

template<typename T> void my_swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void quick_sort(int* p, int n) {
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
			swap(p[l], p[r]);
	} while (r >= l);
	swap(p[l], p[n - 1]);
	quick_sort(&p[0], l);
	quick_sort(&p[l + 1], n - l - 1);
}


void merge_sort(int* num, int l, int r)
{
	int middle = (l + r) / 2, *tmp, lp=l, rp=middle+1;
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
	for (int i = 0, j=l; i < r - l + 1; i++, j++)
	{
		num[j] = tmp[i];
	}
	delete[] tmp;
}

void bubble_sort(int* num, int l, int r)
{
	for (int i = r-1; i>=l; i--)
	{
		int flag = 0;
		for (int j = l; j <= i; j++)
		{
			if (num[j] > num[j + 1])
			{
				flag = 1;
				swap(num[j], num[j + 1]);
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

int search(int* num, int l, int r, int obj)
{
	int mid = (l + r) / 2;
	if (num[l]==obj)
	{
		return l;
	}
	if (num[r] == obj)
	{
		return r;
	}
	if (l == r)
	{
		return -1;
	}
	else
	{
		if (obj >= num[mid])
		{
			search(num, mid, r, obj);
		}
		else if (obj < num[mid])
		{
			search(num, l, mid-1, obj);
		}
	}
}

int search_iterative(int* num, int l, int r, int obj)
{
	while ((l < r)&&(num[l]!=obj)&&(num[r]!=obj))
	{
		int mid = (l + r) / 2;
	    if (obj <= num[mid])
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	if (num[l] == obj)
		return l;
	if (num[r] == obj)
		return r;
	if (l == r)
		return -1;
}



int test_sort_search()
{
	genseeds();
	//int n, *num,*num2;
	//cin >> n;
	//num = new int[n];
	//num2 = new int[n];
	//srand((unsigned)time(NULL));
	//for (int i = 0; i < n; i++)
	//{
	//	num[i] = rand()%20;
	//	num2[i] = num[i];
	//}

	//merge_sort(num, 0, n - 1);
	////bubble_sort(num2, 0, n - 1);
	//for (int i = 0; i < n; i++)
	//	cout << num[i] << ' '<<i<<endl;

	//int result=search_iterative(num, 0, n - 1, 15);
	//cout << result;

	//delete[] num;
	//delete[] num2;
	for (int i = 0; i < 100000; i++) {
		test[i] = rand() % 2000;
	}
	return 0;
}

/*int flag = 1;
	for (int i = 0; i < n; i++)
	{
		if (num[i] != num2[i])
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		cout << "correct";
	else if (flag == 0)
		cout << "incorrect";*/