#include<iostream>
using namespace std;

int main()
{	
	int a;
	long long int b[100000];
	cin >> a;
	b[0] = 2;
	int k = 1;
	cout << b[0] << endl;
	for (int i = 3; i <= a; i++)
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
			cout << b[k] << endl;
			k++;
		}
	}
}