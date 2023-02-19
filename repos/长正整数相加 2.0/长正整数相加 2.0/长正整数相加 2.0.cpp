#include<iostream>
using namespace std;

char a[105], b[105];

int main()
{
	cin >> a >> b;
	for (int i =strlen(a)-1;i>=0; i--)
	{
		a[105 - strlen(a) + i] = a[i];
		a[i] = 0;
	}
	for (int i = 0; i < strlen(b); i++)
	{
		b[105 - strlen(b) + i] = b[i];
	}

}