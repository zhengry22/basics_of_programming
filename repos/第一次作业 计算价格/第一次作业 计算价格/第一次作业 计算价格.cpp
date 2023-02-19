#include<iostream>
using namespace std;

int main()
{
	int a, b, c,p;
	cin >> a;
	cin >> b;
	cin >> c;
	if (a < 0 || a>200 || b < 0 || b>200 || c < 0 || c>200)
	{
		cout << "the weight is invalid!";
	}
	else
	{
		p = 3 * a + 2 * b + 8 * c;
		cout << p << endl;
	}
	return 0;
}