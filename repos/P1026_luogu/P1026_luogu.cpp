#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> mes, word, words; string art;
int cnt[7][201], start[7][201]; int total[201], bool sliced[201];

void deduplicate() {
	vector<int> redun;
	for (int i = 0; i < word.size(); i++) {
		for (int j = i + 1; j < word.size(); j++) {
			if (word[i].find(word[j]) == 0 || word[j].find(word[i]) == 0) {
				word[i].size() > word[j].size() ? redun.push_back(i) : redun.push_back(j);
			}
		}
	}
	for (int i = 0; i < word.size(); i++) {
		int flag = 0;
		for (int j = 0; j < redun.size(); j++) {
			if (i == redun[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) words.push_back(word[i]);
	}
}

void merge() {
	for (auto e : mes) {
		art=art+e;
	}
}

int minus(int a) {
	if (a > 0)return a - 1;
	else return 0;
}

int main() {
	int p, k, s;
	cin >> p >> k;
	mes.resize(p);
	for (int i = 0; i < p; i++) {
		cin >> mes[i];
	}
	cin >> s;
	word.resize(s);
	for (int i = 0; i < s; i++) {
		cin >> word[i];
	}
	deduplicate();
	merge(); int sign = 0;
	for (auto e : words) {
		for (int i = 0; i < art.size() - e.size() + 1; i++) {
			string tmp = art.substr(i, e.size());
			if (tmp == e) {
				start[sign][i] == 1;
				for (int j = i+1; j < i + e.size(); j++) {
					cnt[sign][j]++;
				}
			}
		}
		sign++;
	}
	for (int i = 1; i<art.size(); i++) {
		for (int j = 0; j < words.size(); j++) {
			total[i] += cnt[j][i];
		}
	}
	for (int i = 1; i < k; i++) {//each slice
		
		int mint = total[1], address = 1;
		for (int j = 1; j < art.size(); j++) {
			if (total[j] < mint && !sliced[j]) {
				address = j;
				mint = total[j];
			}
		}
		sliced[address] = true;
		for (int j = 0; j < words.size(); j++) {
			
		}
	}
	
	
	return 0;
}