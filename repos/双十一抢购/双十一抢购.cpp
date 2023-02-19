#include<iostream>
using namespace std;

int sal[1000],num[1000],num2[1000];
float buy[1000], prof[1000];

void swap1(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap2(float* a, float* b)
{
	float temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int obj;
	float mon;
	cin >> mon >> obj;
	for (int i = 0; i < obj; i++)
	{
		cin >> buy[i] >> sal[i];
		num[i] = i + 1;
	}
	//每件商品能赚多少？
	for (int i = 0; i < obj; i++)
	{
		if (sal[i] == 0)
			prof[i] = 0;
		else if (sal[i] == 1)
		{
			prof[i] = buy[i] / 2;
			buy[i] = buy[i] / 2;
		}	
	}
	//先对于利润进行排序
	for (int i=obj-2;i>=0; i--)
	{
		int temp,flag = 0;
		for (int j = 0; j <= i; j++)
		{
			if ((prof[j] < prof[j + 1])||((prof[j] == prof[j + 1])&&(buy[j]>buy[j+1])))
			{
				flag = 1;
				swap2(&prof[j], &prof[j + 1]);
				swap1(&num[j], &num[j + 1]);
				swap2(&buy[j], &buy[j + 1]);
			}
		}
		if (flag == 0)
			break;
	}

	int flag2 = 0,k=0;
	for (int i = 0; i < obj; i++)
	{
		if (buy[i] <= mon)
		{
			flag2 = 1;
			num2[k] = num[i];
			k++;
			mon = mon - buy[i];
		}
	}
	if(flag2 == 0)
	{ 
		cout << 0;
		return 0;
	}
		
	else {
		//最后，再把取出来的序号进行排序,再冒个泡
		for (int i = k - 2; i >= 0; i--)
		{
			int temp1, flag3 = 0;
			for (int j = 0; j <= i; j++)
			{
				if (num2[j] > num2[j + 1])
				{
					flag3 = 1;
					swap1(&num2[j], &num2[j + 1]);
				}
			}
			if (flag3 == 0)
				break;
		}
		for (int i = 0; i < k; i++)
		{
			cout << num2[i] << ' ';
		}
		return 0;
	}	
}