#include<iostream>
using namespace std;

int st[1000];
int ed[1000];

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bbsort(int n)
{
	for (int i = n - 2; i >= 0; i--)
	{
		int flag = 0;
		for (int j = 0; j <= i; j++)
		{
			if (st[j] > st[j + 1])
			{
				flag = 1;
				swap(&st[j], &st[j + 1]);
				swap(&ed[j], &ed[j + 1]);
			}
		}
		if (flag == 0)
			break;
	}
}

int main()
{
	int n,start,ending;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> st[i] >> ed[i];
	}
	//�Ȱѻ�õ���ô���߶ΰ���start��С�����˳���������
	bbsort(n);
	//�����߶��Ѿ�����start��С������������
	int length = ed[0] - st[0];
	for (int i = 1; i < n; i++)
	{
		if ((st[i] <= ed[i - 1])&&(ed[i]>ed[i-1]))
		{
			length = length + (ed[i] - st[i]) - (ed[i-1]-st[i]);
		}
		else if ((st[i] <= ed[i - 1]) && (ed[i] <= ed[i-1]))
		{
			//���Ȳ��ı䣬����Ҫ����һ�β������߶ν��иı�
			ed[i] = ed[i - 1];
			st[i] = st[i - 1];
		}
		else if (st[i] > ed[i - 1])
		{
			length = length + (ed[i] - st[i]);
		}
	}
	
	cout << length;
	return 0;
}