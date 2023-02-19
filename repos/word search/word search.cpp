#include<iostream>
#include<cstring>
using namespace std;

char word1[100][100], word2[100][100];
char w[8] = "yizhong";

void program(int i, int j, int n)
{
	int jdg[8]={1,1,1,1,1,1,1,1};
	for (int k = 1; k <= 6; k++)
	{
		if ((word1[i][j + k] != w[k]) || (j + k < 0) || (j + k >= n))
		{
			jdg[0] = 0;
			break;
		}			
	}
	for (int k = 1; k <= 6; k++) {
		if ((word1[i - k][j + k] != w[k]) || (j + k < 0) || (j + k >= n) || (i - k < 0) || (i - k >= n))
		{
			jdg[1] = 0;
			break;
		}		
	}
	for (int k = 1; k <= 6; k++) {
		if ((word1[i - k][j] != w[k]) || (i - k < 0) || (i - k >= n))
			jdg[2] = 0;
	}
		
		
		if ((word1[i - k][j - k] != w[k])||(i - k < 0) || (i - k >= n)|| (j - k < 0) || (j - k >= n))
			jdg[3] = 0;
		if ((word1[i][j - k] != w[k]) || (j - k < 0) || (j - k >= n))
			jdg[4] = 0;
		if ((word1[i + k][j - k] != w[k]) || (j - k < 0) || (j - k >= n)|| (i + k < 0) || (i + k >= n))
			jdg[5] = 0;
		if ((word1[i + k][j] != w[k])|| (i + k < 0) || (i + k >= n))
			jdg[6] = 0;
		if ((word1[i + k][j + k] != w[k]) || (j + k < 0) || (j + k >= n)|| (i + k < 0) || (i + k >= n))
			jdg[7] = 0;
	}
	for (int k = 0; k < 7; k++)
	{
		if (jdg[0] == 1)
		{
			word2[i][j + k] = w[k];
		}
		if (jdg[1] == 1)
		{
			word2[i - k][j + k] = w[k];
		}
		if (jdg[2] == 1)
		{
			word2[i - k][j] = w[k];
		}
		if (jdg[3] == 1)
		{
			word2[i - k][j - k] = w[k];
		}
		if (jdg[4] == 1)
		{
			word2[i][j - k] = w[k];
		}
		if (jdg[5] == 1)
		{
			word2[i + k][j - k] = w[k];
		}
		if (jdg[6] == 1)
		{
			word2[i + k][j] = w[k];
		}
		if (jdg[7] == 1)
		{
			word2[i + k][j + k] = w[k];
		}

	}
}

int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> word1[i][j];
	}
	memset(word2, '*', sizeof(char) * 10000);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (word1[i][j] == 'y')
			{
				program(i, j, n);
			}
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << word2[i][j];
		}
		cout << endl;
	}
	return 0;
}