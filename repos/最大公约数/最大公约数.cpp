#include<iostream>
using namespace std;

int row[10];
int number[10][2010];
int result[10]={0};

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int gcd(int a, int b)
{
	if (a < b)
		swap(&a, &b);
	while (b != 0)
	{
		a = a % b;
		swap(a, b);
	}
	return a;
}

int main()
{
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> row[i];
		for (int j = 0; j < row[i]; j++)
		{
			cin >> number[i][j];
		}
	}
	//对于每一行进行最大的最大公约数的计算
	for (int i = 0; i < test; i++)
	{
		for (int j=0; j<=row[i]-2; j++)
		{
			for (int k = j+1; k < row[i]; k++)
			{
				if (gcd(number[i][j], number[i][k]) > result[i])
					result[i] = gcd(number[i][j], number[i][k]);
			}
		}
		cout << result[i] << endl;
	}
	return 0;
}