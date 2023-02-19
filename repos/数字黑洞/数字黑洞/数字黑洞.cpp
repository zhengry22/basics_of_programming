#include<iostream>
using namespace std;

void pl(int b[4])
{
	int temp;
	//b0-b3从小到大
	for(int i=2;i>=0;i--)
	{
		for (int j = 0; j<=i; j++)
		{
			if (b[j] >= b[j + 1])
			{
				temp = b[j + 1];
				b[j + 1] = b[j];
				b[j] = temp;
			}
		}
	}
}


int main()
{
	int a,b[4],max,min,p;
	p = 0;
	cin >> a;
	if (a < 1000 || a>9999||(a%1111==0))
	{
		cout << "error" << endl;
	}
	else
	{
		for (int m = 1;; m++)
		{
			//将a的四位数码存到数组里进行排列
			for (int i = 0; i < 4; i++)
			{
				b[i] = a % 10;
				a = a / 10;
			}
			pl(b);
			max = b[0] + 10 * b[1] + 100 * b[2] + 1000 * b[3];
			min = 1000 * b[0] + 100 * b[1] + 10 * b[2] + b[3];
			a = max - min;
			p++;
			if (a == 6174)
			{
				break;
			}
		}
		cout << p << endl;

	}
	return 0;
}
