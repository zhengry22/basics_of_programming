#include<iostream>
#include<vector>
using namespace std;

class det {
public:
	vector<vector<int>> mtx;
	int size;
	void resize(int n) {
		size = n;
		mtx.resize(n + 1);
		for (int i = 0; i < n+1; i++) {
			mtx[i].resize(n+1);
		}
	}
	void give(int row, int col, int num) {
		mtx[row][col] = num;
	}

	int calc_det();
};

int odd_even(int a) {
	return a%2 == 0 ? 1 : -1;
}

int det::calc_det() {
	if (size == 1) return mtx[1][1];
	det son; son.resize(size - 1); int result=0;
	for (int i = 1; i <= size; i++) {//该循环代表n个第一行的元
		for (int j = 2; j <= size; j++) {//col
			int flag = 0;
			for (int k = 1; k <= size; k++) {
				if (k == i) { flag = 1; continue; }
				else if(flag==0) {
					son.mtx[j - 1][k] = mtx[j][k];
				}
				else {
					son.mtx[j - 1][k - 1] = mtx[j][k];
				}
			}
		}
		result += mtx[1][i]*odd_even(1+i) * son.calc_det();
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	det d;
	d.resize(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> d.mtx[i][j];
		}
	}
	int result = d.calc_det();
	cout << result;
	return 0;
}

