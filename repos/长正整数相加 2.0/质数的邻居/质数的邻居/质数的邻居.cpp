#include<iostream>
using namespace std;

int t,r;
int* n;
bool *range;



int main()
{
	cin >> t >> r;
	n = new(int[t]);
	
	for (int i = 0; i < t; i++)
	{
		cin >> n[i];
	}

	//进行素数筛查
	for (int i = 0; i < t; i++)
	{
		range = new(bool[n[i] + r+1]);
		for (int j = 0; j <(n[i]+r+1); j++)
		{
			range[i] = 1;
		}
		//先考虑输入的n比r大的情况
		if (n[i] > r)
		{
			int flag = 0;
			//下面这个二重循环可以把所有范围内的素数全部找出来并排除
			for (int j = 2; j * j <= n[i] + r; j++)
			{
				if (range[j])
				{
					for (int k = j * j; k <= n[i] + r; k = k + j)
					{
						range[k] = 0;
					}
				}
			}
			for (int j = 0; j <= 2 * r; j++)
			{
				if ((range[j+n[i]-r])&&(j != r))
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				cout << 'F' << endl;
			}
			if(flag==1)
			{
				cout << 'T' << endl;
			}
			delete range;
		}
		else
		{
			int flag1 = 0;
			//下面这个二重循环可以把所有范围内的素数全部找出来并排除
			for (int j = 2; j * j <= n[i] + r; j++)
			{
				if (range[j])
				{
					for (int k = j * j; k <= n[i] + r; k = k + j)
					{
						range[k] = false;
					}
				}
			}
			for (int j = 2; j <= n[i]+r; j++)
			{
				if ((range[j]) && (j != n[i]))
				{
					flag1 = 1;
					break;
				}
			}
			if (flag1 == 0)
			{
				cout << 'F' << endl;
			}
			if(flag1==1)
			{
				cout << 'T' << endl;
			}
			delete range;
		}
	}
	return 0;
}