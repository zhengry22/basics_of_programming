#include<iostream>
#include<string.h>
#include<string>
#include<cstring>
using namespace std;

string a[101], b[101];
int x[101], y[101], z[101], n,p[101][2];

int main()
{
	int q = -1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		getchar();
		cin >> x[i];
		getchar();
		cin >> y[i];
	}
	//拿aj一个个和ai比
	for (int i = 0; i < n; i++)
	{
		int k = 0;
		int r = 1;
		int j;
		if (z[i] > 0)
		{
			continue;
		}
		for (j = i + 1; j < n; j++)
		{
			if (x[j] == x[i] && y[j] == y[i])
			{
				k = 1;
				z[j] = i + 1;
				q++;
				break;
			}
		}
		if(k==1)
		{
			//把日期，名字存到相应的二维数组里
			/*cout << x[i] << ' ' << y[i] << ' ';
			cout << a[i] << ' '<<a[j]<<' ';*/
			p[q][0] = x[i];
			p[q][1] = y[i];
			b[q]= a[i];
			b[q]= a[i]+" "+a[j];
			for (int m = j+1; m < n; m++)
			{
				if (x[m] == x[i] && y[m] == y[i])
				{
					r++;
					b[q]=b[q]+" "+a[m];
					z[m] = i + 1;
				}
			}
		}
	}
	//按照日期排列,冒泡，大的向下走
	for (int i = 0; i <= q-1; i++)
	{
		for (int j = 0; j <= q-1-i; j++)
		{
			if (((p[j][0] * 100) + p[j][1]) > ((p[j + 1][0] * 100) + p[j+1][1]))
			{
				int temp1, temp2;
				string cc;
				temp1 = p[j][0];
				temp2 = p[j][1];
				p[j][0] = p[j + 1][0];
				p[j][1] = p[j + 1][1];
				p[j + 1][0] = temp1;
				p[j + 1][1] = temp2;
				cc = b[j];
				b[j] = b[j + 1];
				b[j + 1] = cc;
			}
		}
	}
	while (q >= 0)
	{
		for (int i = 0; i <= q; i++)
		{
			cout << p[i][0] << ' ' << p[i][1] << ' ' << b[i] << endl;
		}
		break;
	}
	return 0;
}