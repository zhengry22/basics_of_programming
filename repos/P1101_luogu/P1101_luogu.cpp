#include<iostream>
#include<cstring>
#include<string>
using namespace std;

struct directions {
	int row;
	int col;
};

char word_search[101][101];
char word_output[101][101];
string answer = "yizhong";
directions direct[8] = {0,1,-1,1,-1,0,-1,-1,0,-1,1,-1,1,0,1,1};

void traverse(int row, int col, int n)//row����main�б�����ÿһ��Ԫ�ص��У�col���У�n����һ��ʼ��������n
{
	for (int num = 0; num < 8; num++)//8 dirs
	{
		int flag = 1;
		for (int i = row, j = col, times = 0; times < 7; i += direct[num].row, j += direct[num].col, times++)//��ͬ����ļӷ�ȡ����direct�����
		{
			if (i>n||i<1||j>n||j<1)
			{
				flag = 0;
				break;
			}
			else if (word_search[i][j] != answer[times])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			for (int i = row, j = col, times = 0; times < 7; i += direct[num].row, j += direct[num].col, times++)
				word_output[i][j] = word_search[i][j];
	}
}



int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)//i is row
	{
		for (int j = 1; j <= n; j++)//j is col
			cin >> word_search[i][j];
	}
	memset(word_output, '*', sizeof(char) * 101 * 101);
	//traverse
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			//8 directions
			if (word_search[i][j] == 'y')
			{
				traverse(i, j, n);
			}
		}
	}
	for (int i = 1; i <= n; i++)//i is row
	{
		for (int j = 1; j <= n; j++)//j is col
		{
			cout << word_output[i][j];
		}
		cout << endl;
	}
	return 0;
}