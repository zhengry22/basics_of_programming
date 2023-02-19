//#define debugg 1
#include<iostream>
//#include<queue>
#ifdef debugg
#include<vector>
#include <iomanip>
#endif
#include<cstring>

using namespace std;


int changes[100];
int datastore[55000][60];
int n, maximum;

struct info {
	int begin;
	int lev;
};

#ifdef debugg
vector<info> tree;
#endif // debugg



int judge(int begin, int lev) {
	if (begin + changes[lev] <= maximum && begin + changes[lev] >= 0) {
		if (begin - changes[lev] <= maximum && begin - changes[lev] >= 0) return 3;
		else return 2;
	}
	else {
		if (begin - changes[lev] <= maximum && begin - changes[lev] >= 0) return 1;
		else return 0;
	}
}

int calc(int begin, int lev) {
	if (begin + changes[lev] <= maximum && begin + changes[lev] >= 0) {
		return begin + changes[lev];
	}
	else {
		return ((begin - changes[lev] >= 0) && (begin - changes[lev] <= maximum)) ? begin - changes[lev] : -1;
	}
}

int tune(int begin, int lev) {//at 0£¬ lev 1
	if (datastore[begin][lev] != -2) {
#ifdef debugg	
		tree.push_back({ datastore[begin][lev],lev });
		for (auto e : tree) {
			cout << setw(5) << e.begin << ' ';
		}
		cout << endl;
		tree.pop_back();
#endif
		return datastore[begin][lev];
	}
	else {
		if (lev == n) {
			/*int answer=calc(begin, lev);
			tree.push_back({answer, lev});
			for (auto e : tree) {
				
				cout <<setw(5)<< e.begin<<' ';
			}
			cout << endl;
			tree.pop_back();
			return answer;*/
			switch (judge(begin, lev)){
			case 0: {
				//tree.push_back({ -1, lev });
				/*for (auto e : tree) {
					cout << setw(5) << e.begin << ' ';
				}
				cout << endl;*/
				//tree.pop_back();
				return -1;
			}
			case 1: {
				//tree.push_back({ begin - changes[lev], lev });
			/*	for (auto e : tree) {
					cout << setw(5) << e.begin << ' ';
				}
				cout << endl;*/
				//tree.pop_back();
				return begin - changes[lev];
			}
			case 2: {
				//tree.push_back({ begin + changes[lev], lev });
				/*for (auto e : tree) {
					cout << setw(5) << e.begin << ' ';
				}
				cout << endl;*/
				//tree.pop_back();
				return begin + changes[lev];
			}
			case 3: {
				//tree.push_back({ begin - changes[lev], lev });
				//for (auto e : tree) {
				//	cout << setw(5) << e.begin << ' ';
				//}
				//cout << endl;
				//tree.pop_back();
				//tree.push_back({ begin + changes[lev], lev });
				/*for (auto e : tree) {
					cout << setw(5) << e.begin << ' ';
				}
				cout << endl;*/
				//tree.pop_back();
				return begin - changes[lev] > begin + changes[lev] ? begin - changes[lev] : begin + changes[lev];
			}

			}
		}
		else {
			switch (judge(begin, lev))
			{
				case 0: {
					//tree.push_back({-1, lev});
					/*for (auto e : tree) {
						cout << setw(5)<< e.begin<<' ';
					}
					cout << endl;*/
					//tree.pop_back();
					return -1;
				}
				case 1: {
					//tree.push_back({ begin - changes[lev], lev});
					datastore[begin - changes[lev]][lev + 1] = tune(begin - changes[lev], lev + 1);
					//tree.pop_back();
					return datastore[begin - changes[lev]][lev + 1];
				}
				case 2: {
					//tree.push_back({ begin + changes[lev], lev });
					datastore[begin + changes[lev]][lev + 1] = tune(begin + changes[lev], lev + 1);
					//tree.pop_back();
					return datastore[begin + changes[lev]][lev + 1];
				}
				case 3: {
					//tree.push_back({ begin - changes[lev], lev });
					datastore[begin - changes[lev]][lev + 1] = tune(begin - changes[lev], lev + 1);
					//tree.pop_back();
					//tree.push_back({ begin + changes[lev], lev });
					datastore[begin + changes[lev]][lev + 1] = tune(begin + changes[lev], lev + 1);
					//tree.pop_back();
					return datastore[begin - changes[lev]][lev + 1] > datastore[begin + changes[lev]][lev + 1] ? datastore[begin - changes[lev]][lev + 1] : datastore[begin + changes[lev]][lev + 1];
				}

			}
		}
	}
}

int main() {
	int begin;
	for (int i = 0; i < 55000; i++) {
		for (int j = 0; j < 60; j++) {
			datastore[i][j] = -2;
		}
	}
	cin >> n >> begin >> maximum;
	for (int i = 1; i <= n; i++) {
		cin >> changes[i];
	}
	int result=tune(begin, 1);
	cout << result;
	return 0;
}