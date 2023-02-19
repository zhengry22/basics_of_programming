#include<iostream>
using namespace std;

struct birthday{
	string name;
	int month;
	int date;
	int num;
};

birthday students[101];

template<typename T> void my_swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T, typename U>
void bubble_sort(T* num, int l, int r, U rule)//l,r不是哨兵
{
	for (int i = r - 1; i >= l; i--)
	{
		int flag = 0;
		for (int j = l; j <= i; j++)
		{
			if (!rule(num[j], num[j + 1]))//括号里是与排序规则相反的条件
			{
				flag = 1;
				my_swap(num[j], num[j + 1]);
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

class sort_birth {
public:
	bool operator() (birthday a, birthday b) {
		return (a.month < b.month) || (a.month == b.month && a.date < b.date)|| (a.month == b.month && a.date == b.date&&a.num<b.num);
	}
};

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> students[i].name;
		cin >> students[i].month >> students[i].date;
		students[i].num = i;
	}
	bubble_sort(students, 1, n, sort_birth());
	int tmp_date = 0, tmp_month = 0; int sign = 0; int start = 0, end = 0;
	for (int i = 1; i <= n; i++) {
		
		if (students[i].date == tmp_date && students[i].month == tmp_month) {
			start++;
			if (start == 1)cout << students[i].month << ' ' << students[i].date << ' ';
			cout << students[i - 1].name << ' ';
			end = 1;
		}
		else {
			start = 0;
			if(end==1)
				cout << students[i - 1].name << endl;
			end = 0;
		}
		tmp_date = students[i].date;
		tmp_month = students[i].month;
		sign = start;
	}
	if (sign != 0)cout << students[n].name;
	return 0;
}