#include<stdio.h>
#include<math.h>
int fact(int n)
{
	if (n < 0)
	{
		return 0;
	}
	else if (n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return n * fact(n - 1);
	}
}

void swap(int *a, int *b)//实现对于两个数的交换，注意自变量是地址形
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void px(int a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	for (int i = 1;i<fact(n); i++)
	{
		int j = 1;
		end:
		if (i % fact(j) == 0 && i % fact(j + 1) == 0)
		{
			j++;
			goto end;
		}
		else if (i % fact(j) == 0 && i % fact(j + 1) != 0)
		{
			swap(&a[j-1], &a[j]);
			for (int i = 0; i < n; i++)
			{
				printf("%d", a[i]);
			}
		}
	}

}

int main()
{
	int a[50];
	int i, n;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	px(a, n);
	return 0;
}