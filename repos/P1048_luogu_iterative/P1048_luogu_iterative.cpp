#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int val[101][1001];

int main()
{
	memset(val, 0, sizeof(int) * 1001 * 101);
	int time, num;
	cin >> time >> num;
	vector<int> price(num + 1);
	vector<int> tm(num + 1);
	for (int i = 1; i <= num; i++)
	{
		cin >> tm[i] >> price[i];
	}
	for (int i = 1; i <= num; i++){
		for (int j = 1; j <= time; j++){
			if (j - tm[i] >= 0){
				val[i][j] = val[i - 1][j] > val[i - 1][j - tm[i]]+price[i] ? val[i - 1][j] : val[i - 1][j - tm[i]] + price[i];
			}
			else {
				val[i][j] = val[i - 1][j];
			}
		}	
	}
	cout << val[num][time];
	return 0;

}