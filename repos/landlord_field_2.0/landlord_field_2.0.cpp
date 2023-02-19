#include<iostream>
#define MIN -20000001
using namespace std;

int sum[101][101][101][101];

int field[101][101];

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n, m, most=MIN;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> field[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {//i,j代表终止点
			//求和
			for (int x = 1; x <= i; x++) {
				for (int y = 1; y <= j; y++) {
					sum[1][1][i][j] += field[x][y];
					
				}
			}
		//	cout << i << ' ' << j << ' ' << sum[1][1][i][j] << endl;
			most = most>sum[1][1][i][j]?most: sum[1][1][i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {//i,j是起点
			if (i == 1 && j == 1)continue;
			for (int x = i; x <= n; x++) {
				for (int y = j; y <= m; y++) {//x,y是终点
					if (j == 1) {
						sum[i][j][x][y] = sum[1][1][x][y] - sum[1][1][i-1][y];
						most = most > sum[i][j][x][y] ? most : sum[i][j][x][y];
					}
					else if (i == 1) {
						sum[i][j][x][y] = sum[1][1][x][y] - sum[1][1][x][j-1];
						most = most > sum[i][j][x][y] ? most : sum[i][j][x][y];
					}
					else {
						sum[i][j][x][y]=sum[1][1][x][y]-sum[1][1][i-1][y]-sum[1][1][x][j-1]+sum[1][1][i-1][j-1];
						most = most > sum[i][j][x][y] ? most : sum[i][j][x][y];
					}
				}
			}
		}
	}
	cout << most;
	return 0;
}