#include<iostream>
#include<cstring>
using namespace std;

int numbers[50001]; int n;
int datastore[50001];

int steps(int lev) {
	if (datastore[lev] != -1) return datastore[lev];
	if (lev == n) return 0;
	if (numbers[lev] == 0) return 1000000;
	else {
		int upper = lev + numbers[lev] > n ? n : lev + numbers[lev]; 
		for (int i = lev + 1; i <= upper; i++) {
			datastore[i] = steps(i);
		}
			int minimum = 1+datastore[lev + 1];
		for (int i = lev + 1; i <= upper; i++) {
			minimum = minimum < 1 + datastore[i] ? minimum : 1+datastore[i];
		}
		return minimum;
	}
}

int main() {
	memset(datastore, -1, sizeof(int) * 50001);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> numbers[i];
	}
	int answer = steps(1);
	cout << answer;
	return 0;
}

//��⣺��������Ŀ����һ����ԭ�����һ����ͬ������������ȥ˼������Ϊ����ÿһ���ӽڵ����滹������
//����lev��������ߵ�lev+1��min��lev+numbers[lev+1], n���񣬶�ʵ�ʵĴ�����steps[lev]=min{1+steps[lev+1], 1+steps[lev+2], ... 1+steps[i+numbers[i]]}
//�ӣ���memsetʱ�ύoj��Ҫcstring�� 
//ע��minimum��datastore�Ľ�����ܲ��Ǻ�������ֵ������Ҫ�Ӽ�һЩ����
//ע����Ŀ˵�����ǡ��������ǡ��Ǹ���