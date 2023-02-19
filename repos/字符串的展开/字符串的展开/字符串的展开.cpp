#include<iostream>
#include<cstring>
using namespace std;

char str[100];
int p1, p2, p3,length;

void reverse(char* a, int b)
{
	for (int i = 1; i <= (b + 1) / 2; i++)
	{
		int temp = *(a + i - 1);
		*(a + i - 1) = *(a + b - i);
		*(a + b - i) = temp;
	}
}

void leftmove(char* a, char* b)
{
	for (char* i = a; i <= b; i++)
	{
		*(i - 1) = *i;
	}
	*b = '\0';
}

void rightmove(char* a, char* b, int p, int sign1, int sign2, int sign3)
{
	char x = *a, y = *(a - 2);
	for (char* i = b; i >= a; i--)
	{
		*(i + p) = *i;
	}
	for (char* j = a-1; j < a + p; j++)
	{
		if (sign1 == 1)
		{
			*j = (*(a - 2) + ((j + 1 - a + sign2)) / sign2);
		}
		else if (sign1 == 2)
		{
			if (x >= 97 && x <= 122&&y>=97&&y<=122)
			{
				*j = (*(a - 2) - 32 + ((j + 1 - a + sign2)) / sign2);
			}
			else
			{
				*j = (*(a - 2) + ((j + 1 - a + sign2)) / sign2);
			}
		}
		else if(sign1==3)
		{
			*j = '*';
		}
	}
	if (sign3 == 2)
	{
		reverse(a - 1, p+1);
	}
}

int main()
{
	cin >> p1 >> p2 >> p3;
	cin >> str;
	length = strlen(str);
	for (int i = 0; i < strlen(str); i++)
	{
		//ÌÚ³ö¿ÕÎ»
		if (str[i] == '-' && (int(str[i + 1]) == int(str[i - 1]) + 1))
		{
			leftmove(&str[i+1], &str[length]);
			length = strlen(str);
		}
		else if (str[i] == '-' && (int(str[i + 1]) > int(str[i - 1]) + 1))
		{
			rightmove(&str[i+1], &str[length], (str[i + 1] - str[i - 1] - 2 + (p2 - 1) * (str[i + 1] - str[i - 1] - 1)),p1,p2,p3);
			length = strlen(str);
		}
	}
	cout << str;
	return 0;
}