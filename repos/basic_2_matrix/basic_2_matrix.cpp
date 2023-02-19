#include<iostream>
#include<iomanip>
using namespace std;

int matrix[500][500];  int number = 1;
int x, y;	int n;

struct pos {
	int row;
	int col;
};

pos dir[4] = { {1,0},{0,-1},{-1,0},{0,1} };

bool turn(int x, int y, int state) {
	if (x + dir[state].row<1 || y + dir[state].col<1 || x + dir[state].row>n || y + dir[state].col>n || matrix[x + dir[state].row][y + dir[state].col] != 0) return true;
	else return false;
}


void circ() {
	int state = 0;
	while (number<=n*n) {
		matrix[x][y] = number; 
		x+=dir[state % 4].row;
		y += dir[state % 4].col;
		number++;
		if (turn(x, y, state % 4)) {
			state++;
		}
	}
}

int main() {

	cin >> n;
	x = 1; y = n;
	circ();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << setw(5)<<matrix[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}