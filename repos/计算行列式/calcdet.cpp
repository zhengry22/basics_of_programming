#include<iostream>
using namespace std;

int **mtx;

int det(int n, int row, int column[])
{
	int sum = 0;
	if (n == 1)
		return mtx[0][0];
	else if (n >= 2)

		
		
}

int main()
{
	int n;
	cin >> n;
	mtx = new int*[n];
	for (int i = 0; i < n; i++)
	{
		mtx[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> mtx[i][j];
	}

	
	
	return 0;
}