#include<iostream>
using namespace std;

int n;
int* number;

void order(int* a, int* b)
{
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

int main()
{
	cin >> n;
	number = new(int[n]);
	for (int i = 0; i < n; i++)
	{
		cin >> number[i];
	}
	//�ȶ�number����������ݽ���ð������,С����ǰ������ں�
	for (int i = 0; i < n-1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (number[j] >= number[j + 1])
			{
				flag = 1;
				order(&number[j], &number[j + 1]);
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
	//������ȥ����ͬ����
	int p = n;
	for (int i = p-2; i>=0; i--)
	{
		if (number[i]==number[i + 1])
		{
			for (int j = i; j <= n - 2; j++)
			{
				number[j] = number[j + 1];
			}
			n--;
		}
	}
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		cout << number[i] << ' ';
	}
	delete number;
	return 0;
}