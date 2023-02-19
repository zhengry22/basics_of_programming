#include<iostream>
using namespace std;

long long ways = 0; int n,x,y;
int chess[15][15]; int row_sign[15], col_sign[15], left_diag[29], right_diag[29];

void deposit(int row, int numbers) {
	if (numbers == n) { ways++; return; }
	//put the first queen
	for (int i = 1; i <= n; i++){
		//first check if the square is occupied
		if (row_sign[row]==1||col_sign[i]==1|| left_diag[row - i + n + 1] == 1|| right_diag[row + i - 1] == 1||(row==x&&i==y)) continue;
		//else, potential spare place, mark the areas occupied
		else {
			row_sign[row] = 1; col_sign[i] = 1; left_diag[row - i + n + 1] = 1; right_diag[row + i - 1] = 1;
			//deposit the next queen
			deposit(row + 1, numbers + 1);
			row_sign[row] = 0; col_sign[i] = 0; left_diag[row - i + n + 1] = 0; right_diag[row + i - 1] = 0;
		}
	}
}

int main() {
	cin >> n >> x>>y;
	deposit(1, 0);
	cout << ways;
	return 0;
}