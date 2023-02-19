#define debugg 1
#include<iostream>
#ifdef debugg
#include<vector>
#include<fstream>
#include<iomanip>
#endif
using namespace std;


#ifdef debugg
vector<int> queue;
#endif 

#ifdef debugg
ofstream fout("tree_not_optimized.txt");
#endif

int changes[100];
int datastore[2000][60];
int n, maximum;

inline bool in_range(int a) {
	return a >= 0 && a <= maximum ? true : false;
}

int tune(int begin, int lev) {
#ifdef debugg
	for (int i = 1; i <= lev; i++) {
		fout <<"|   ";
	}
	fout << '|' << '-' << begin << endl;
#endif

	if (datastore[begin][lev] != -2)return datastore[begin][lev];
	if (lev == n) {
		return (in_range(begin)) ? begin : -1;
	}

	else {
		int tmp1=-1, tmp2=-1;
		if (in_range(begin + changes[lev + 1])){
			tmp1=datastore[begin + changes[lev + 1]][lev + 1] = tune(begin + changes[lev + 1], lev + 1);
		}
		if (in_range(begin - changes[lev + 1])) {
			tmp2=datastore[begin - changes[lev + 1]][lev + 1] = tune(begin - changes[lev + 1], lev + 1);
		}
		return tmp1 > tmp2 ? tmp1 : tmp2;
	}
}


int main() {
	int begin;
	for (int i = 0; i < 2000; i++) {
		for (int j = 0; j < 60; j++) {
			datastore[i][j] = -2;
		}
	}
	cin >> n >> begin >> maximum;
	for (int i = 1; i <= n; i++) {
		cin >> changes[i];
	}
	int result = tune(begin, 0);
	cout << result;
	return 0;
}