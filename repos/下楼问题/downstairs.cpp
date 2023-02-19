#include<iostream>
using namespace std;

int ways(int h)
{
	if (h == 1)
		return 1;
	else if (h == 2)
		return 2;
	else if (h == 3)
		return 4;
	else if (h > 3)
		return ways(h - 1) + ways(h - 2) + ways(h - 3);
}

int main()
{
	int h, mtd;
	cin >> h;
	if (h <= 3)
		cout << 0;
	else
		cout << ways(h);
	return 0;
}