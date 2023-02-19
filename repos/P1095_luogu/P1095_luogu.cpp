#include<iostream>
#include<math.h>
#include<cassert>
using namespace std;

long long m, s, t;//m为魔法初值，s为距离，t为总时间
int datastore[1101][310001];

int dist(long long magic, long long time) {
	if (datastore[magic][time] != 0)return datastore[magic][time];
	else {
		if (time == 1) {
			return magic >= 10 ? 60 : 17;
		}
		else {
			if (magic >= 10) {
				datastore[magic - 10][time - 1] = dist(magic - 10, time - 1);
				//cout<<magic-10<<' '<<time-1<<' '<< datastore[magic - 10][time - 1]<<endl;
				return datastore[magic - 10][time - 1] + 60;
			}
			else {
				datastore[magic][time - 1] = dist(magic, time - 1);
				datastore[magic + 4][time - 1] = dist(magic + 4, time - 1);
				//	cout << magic << ' ' << time - 1 << ' ' << datastore[magic][time - 1]<<endl;
					//cout << magic + 4 << ' ' << time - 1 << ' ' << datastore[magic + 4][time - 1] << endl;
				long long tmp = datastore[magic][time - 1] + 17 > datastore[magic + 4][time - 1] ? datastore[magic][time - 1] + 17 : datastore[magic + 4][time - 1];
				return tmp;
			}
		}
	}
}

int main() {
	cin >> m >> s >> t;
	datastore[m][t] = dist(m, t);
	if (datastore[m][t] >= s) {
		cout << "Yes" << endl;
		//cout << datastore[m][t];
	}
	else {
		cout << "No" << endl;
		cout << datastore[m][t];
	}
	return 0;
}