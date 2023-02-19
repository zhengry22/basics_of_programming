#include<iostream>
#include<cstring>
using namespace std;

string a, b;
int flag = 0;
int sign = 0;
int *digit;

int main()
{
	cin >> a >> b;
	if (strlen(a.data()) != strlen(b.data()))
	{
		cout << 1;
	}
	else
	{
		digit = new(int[strlen(a.data())]);
		for (int i = 0; i < strlen(a.data()); i++)
		{
			if (a[i] != b[i])
			{
				flag = 1;
				digit[i] = ((int(a[i]) - int(b[i])) % 32);
				if (digit[i] != 0)
				{
					sign = 1;
				}
			}
		}
		if (flag == 0)
		{
			cout << 2;
		}
		else if (flag == 1 && sign == 0)
		{
			cout << 3;
		}
		else if (flag == 1 && sign == 1)
		{
			cout << 4;
		}
		delete digit;
	}
	return 0;
}
