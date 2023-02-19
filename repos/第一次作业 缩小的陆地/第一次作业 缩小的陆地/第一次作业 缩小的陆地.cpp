#include<iostream>
using namespace std;
#define pi 3.1415926
int main()
{
	float x, y,s;
	int z,m;
	cin >> x >> y;
	if (x > 10000 || x < -10000 || y>10000 || y < 0)
	{
		cout << "input is invalid!";
	}
	else
	{
		s = 0.5 * pi * (x * x + y * y);
		z = s / 50;
		z = z + 1;
		cout << z << endl;

	}
	


	return 0;
}