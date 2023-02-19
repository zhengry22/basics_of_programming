#include<iostream>
using namespace std;

int ar1[1000], ar2[1000],m,n;

void inter(int ar1[], int ar2[],int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ar1[i] == ar2[j])
			{
				cout << ar1[i]<<' ';
				break;
			}
		}
	}
}

void all(int ar1[], int ar2[], int m, int n)
{
	int ar3[2000];
	for (int i = 0; i < m; i++)
	{
		ar3[i] = ar1[i];
	}
	for (int i = 0; i < n; i++)
	{
		ar3[m + i] = ar2[i];
	}
	//ÅÅĞò
	for (int i = m+n-2; i >=0; i--)
	{
		int flag = 0;
		int temp;
		for (int j = 0; j <= i; j++)
		{
			if (ar3[j] > ar3[j + 1])
			{
				flag = 1;
				temp = ar3[j];
				ar3[j] = ar3[j + 1];
				ar3[j + 1] = temp;
			}
		}
		if (flag == 0)
			break;
	}
	//Êä³ö
	cout << ar3[0]<<' ';
	for (int i = 1; i < m + n; i++)
	{
		if (ar3[i] != ar3[i - 1])
			cout << ar3[i]<<' ';
	}
}

void dif(int ar1[], int ar2[], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		int flag = 0;
		for (int j = 0; j < n; j++)
		{
			if (ar1[i] == ar2[j]) 
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			cout << ar1[i]<<' ';
		}
	}
}

int main()
{
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> ar1[i];
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ar2[i];
	}
	inter(ar1, ar2, m, n);
	cout << endl;
	all(ar1, ar2, m, n);
	cout << endl;
	dif(ar1, ar2, m, n);
	return 0;
}