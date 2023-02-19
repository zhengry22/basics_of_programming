#include <stdio.h>
int bi(int a)
{
	if (a == 1)
	{
		return 1;
	}
	else if (a % 2 == 0)
	{
		return 10 * bi(a / 2);
	}
	else if (a % 2 == 1)
	{
		return 1 + bi(a-1);
	}
}
int main()
{
	int a,b;
	scanf_s("%d", &a);
	b = bi(a);
	printf("%d", b);
	return 0;

}