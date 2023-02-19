#pragma warning(disable:4996)
#include<iostream>
#include<cstring>
using namespace std;

int n, m, p, flag = 0;
string order;

struct rubber {
	/*string color;
	string shape;*/
	char color[40];
	char shape[40];
};

rubber rb[1010];

void swap(rubber* a, rubber* b)
{
	rubber tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort()
{
	for (int i = flag - 2; i >= 0; i--)
	{
		int sign = 0;
		for (int j = 0; j <= i; j++)
		{
			//color dictionary order
			int k = 0;
			while (rb[j].color[k] == rb[j + 1].color[k])
			{
				k++;
			}
			if (rb[j].color[k] > rb[j + 1].color[k])
			{
				sign = 1;
				swap(&rb[j], &rb[j + 1]);
			}
		}
		if (sign == 0)
			break;
	}
	for (int i = flag - 2; i >= 0; i--)
	{
		int sign2 = 0;
		for (int j = 0; j <= i; j++)
		{
			//shape dictionary order
			int k = 0;
			if (strcmp(rb[j].color, rb[j+1].color)==0)
			{
				while (rb[j].shape[k] == rb[j + 1].shape[k])
				{
					k++;
				}
				if (rb[j].color[k] > rb[j + 1].color[k])
				{
					sign2 = 1;
					swap(&rb[j], &rb[j + 1]);
				}
			}
		}
		if (sign2 == 0)
			break;
	}
}

void crash(int p)
{
	for (int i = p; i < flag; i++)
	{
		rb[i] = rb[i + 1];
	}
}

int main()
{
	memset(rb, 0, sizeof(rubber) * 1000);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> order;
		if (order == "CREATE")
		{
			cin >> rb[flag].color >> rb[flag].shape;
			flag++;
		}
		else if (order == "DUP")
		{
			cin >> m >>rb[flag].color;
			//rb[flag].shape = rb[m].shape;
			strcpy(rb[flag].shape, rb[m-1].shape);
			flag++;
		}
		else if (order == "CRASH")
		{
			cin >> p;
			crash(p - 1);
			flag--;
		}
		else if (order == "ORDER")
		{
			sort();
		}
	}
	for (int i = 0; i < flag; i++)
	{
		if ((strcmp(rb[i].color, "#")!=0) && (strcmp(rb[i].shape, "#") != 0))
		{
			cout << rb[i].color << ' ' << rb[i].shape << endl;
		}
	}
	return 0;
}