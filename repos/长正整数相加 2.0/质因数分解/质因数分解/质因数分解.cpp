#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b[50000];
	char x = 'A';
	cin >> a;
	if (a < 2 || a>2000000000)
	{
		cout << "error";
	}
	else
	{
		
		//�Ȱ����п��ܳ�������������ɸ���������Ż�
		b[0] = 2;
		int k = 1,m=0;
		for (int i = 3; (i*i)<=a; i++)
		{
			int l = 0;
			for (int j = 0; j <= k - 1; j++)
			{
				if (i % b[j] == 0)
				{
					l = 1;
					break;
				}
			}
			if (l == 0)
			{
				b[k] = i;
				k++;
			}
		}
		//���ж�A/B��
		for (int i=0;i<k; i++)
		{
			if (a % (b[i]*b[i]) == 0)
			{
				x = 'B';
				break;
			}
		}
		cout << x << endl;
		
		//�ٽ�������cout
		int p=0,t=a;
		for (int i = 1;; i++)
		{
			
			if (a % b[p] == 0)
			{
				a = a / b[p];
				cout << b[p] << endl;
			}
			else
			{
				p++;
			}
			if (a==1)
			{
				break;
			}
			else if (p == k && a > 1)
			{
				cout << a << endl;
				break;
			}

		}
	}
	return 0;
}
