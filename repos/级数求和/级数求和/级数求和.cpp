#include<iostream>
using namespace std;

int main()
{
	int n;
	const double a = 1;
	double i;
	double s;
	s = 0;
	cin >> n;
	if (n < 1 || n>15)
	{
		cout << "error" << endl;
	}
	else
	{
		for (i = 1;; i++)
		{
			s = s + a/i;
			if (s > n)
			{
				break;
			}
		}
		cout << (int)i << endl;
	}
	return 0;
}