#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<cstdlib>
#include<time.h>
#include"my_MATH.h"
#define A 1000000007
#define t_length 2000
using namespace std;

struct students {
	string name;
	int height;
};

void quick_sort(int* p, int n) {
	if (n <= 1)
		return;
	int t = p[n - 1], l = 0, r = n - 2;
	do {
		for (; r >= l; l++)
			if (p[l] > t)
				break;
		for (; r >= l; r--)
			if (p[r] < t)
				break;
		if (r >= l)
			swap(p[l], p[r]);
	} while (r >= l);
	swap(p[l], p[n - 1]);
	quick_sort(&p[0], l);
	quick_sort(&p[l + 1], n - l - 1);
}

class compare_int {//下面符合规则的在排列中应该在前面
public:
	bool operator() (int a, int b) {
		return a > b;
	}
};

class compare_student {
public:
	bool operator() (students a, students b) {
		/*for (auto &e : a.name) {
			e=toupper((int)e);
		}
		for (auto& e : b.name) {
			e=toupper((int)e);
		}*/
		return (a.height < b.height)||(a.height == b.height&&a.name<b.name);
	}
};

template<typename T, typename U>
void T_quick_sort(T* p, int n, U rule) {
	if (n <= 1)
		return;
	T t = p[n - 1]; int l = 0, r = n - 2;
	do {
		for (; r >= l; l++)
			if (!rule(p[l], t))
				break;
		for (; r >= l; r--)
			if (rule(p[r], t))
				break;
		if (r >= l)
			swap(p[l], p[r]);
	} while (r >= l);
	swap(p[l], p[n - 1]);
	T_quick_sort(&p[0], l, rule);
	T_quick_sort(&p[l + 1], n - l - 1, rule);
}


void merge_sort(int* num, int l, int r)//l,r分别是最左项和最右项的address，注意r不是哨兵
{
	int middle = (l + r) / 2, *tmp, lp=l, rp=middle+1;
	//when to return 
	if (l == r)
		return;
	//first, merge the left and right part
	merge_sort(num, l, middle);
	merge_sort(num, middle + 1, r);
	//create a new array to dispose number
	tmp = new int[r - l + 1];
	int flag = 0;
	while ((lp <= middle) && (rp <= r))
	{
		if (num[lp] <= num[rp])
		{
			tmp[flag] = num[lp];
			lp++;
		}
		else
		{
			tmp[flag] = num[rp];
			rp++;
		}
		flag++;
	}
	if (lp <= middle)
	{
		for (int i = lp; i <= middle; i++)
		{
			tmp[flag] = num[i];
			flag++;
		}
	}
	if (rp <= r)
	{
		for (int i = rp; i <= r; i++)
		{
			tmp[flag] = num[i];
			flag++;
		}
	}
	//put the numbers in tmp into num
	for (int i = 0, j=l; i < r - l + 1; i++, j++)
	{
		num[j] = tmp[i];
	}
	delete[] tmp;
}

template<typename T, typename U>
void T_merge_sort(T* num, int l, int r, U rule)
{
	T* tmp;
	int middle = (l + r) / 2, lp=l, rp=middle+1;
	//when to return 
	if (l == r)
		return;
	//first, merge the left and right part
	T_merge_sort(num, l, middle, rule);
	T_merge_sort(num, middle + 1, r, rule);
	//create a new array to dispose number
	tmp = new T[r - l + 1];
	int flag = 0;
	while ((lp <= middle) && (rp <= r))
	{
		if (rule(num[lp],num[rp]))//这里是排序规则，服从该规则的元素放在前面
		{
			tmp[flag] = num[lp];
			lp++;
		}
		else
		{
			tmp[flag] = num[rp];
			rp++;
		}
		flag++;
	}
	if (lp <= middle)
	{
		for (int i = lp; i <= middle; i++)
		{
			tmp[flag] = num[i];
			flag++;
		}
	}
	if (rp <= r)
	{
		for (int i = rp; i <= r; i++)
		{
			tmp[flag] = num[i];
			flag++;
		}
	}
	//put the numbers in tmp into num
	for (int i = 0, j=l; i < r - l + 1; i++, j++)
	{
		num[j] = tmp[i];
	}
	delete[] tmp;
}


template<typename T, typename U>//vector 版本
void T_merge_sort(vector<T>& num, int l, int r, U rule)
{
	T* tmp;
	int middle = (l + r) / 2, lp = l, rp = middle + 1;
	//when to return 
	if (l == r)
		return;
	//first, merge the left and right part
	T_merge_sort(num, l, middle, rule);
	T_merge_sort(num, middle + 1, r, rule);
	//create a new array to dispose number
	tmp = new T[r - l + 1];
	int flag = 0;
	while ((lp <= middle) && (rp <= r))
	{
		if (rule(num[lp], num[rp]))//这里是排序规则，服从该规则的元素放在前面
		{
			tmp[flag] = num[lp];
			lp++;
		}
		else
		{
			tmp[flag] = num[rp];
			rp++;
		}
		flag++;
	}
	if (lp <= middle)
	{
		for (int i = lp; i <= middle; i++)
		{
			tmp[flag] = num[i];
			flag++;
		}
	}
	if (rp <= r)
	{
		for (int i = rp; i <= r; i++)
		{
			tmp[flag] = num[i];
			flag++;
		}
	}
	//put the numbers in tmp into num
	for (int i = 0, j = l; i < r - l + 1; i++, j++)
	{
		num[j] = tmp[i];
	}
	delete[] tmp;
}

void bubble_sort(int* num, int l, int r)
{
	for (int i = r-1; i>=l; i--)
	{
		int flag = 0;
		for (int j = l; j <= i; j++)
		{
			if (num[j] > num[j + 1])
			{
				flag = 1;
				swap(num[j], num[j + 1]);
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

template<typename T, typename U>//如果使用一般的数组，就用它
void bubble_sort(T* num, int l, int r, U rule)//l,r不是哨兵
{
	for (int i = r - 1; i >= l; i--)
	{
		int flag = 0;
		for (int j = l; j <= i; j++)
		{
			if (!rule(num[j] , num[j + 1]))//括号里是与排序规则相反的条件
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

template<typename T, typename U>//如果用vector，用它
void bubble_sort(vector<T>& num, int l, int r, U rule)//l,r不是哨兵
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

int search(int* num, int l, int r, int obj)
{
	int mid = (l + r) / 2;
	if (num[l]==obj)
	{
		return l;
	}
	if (num[r] == obj)
	{
		return r;
	}
	if (l == r)
	{
		return -1;
	}
	else
	{
		if (obj >= num[mid])
		{
			search(num, mid, r, obj);
		}
		else if (obj < num[mid])
		{
			search(num, l, mid-1, obj);
		}
	}
}

int search_iterative(int* num, int l, int r, int obj)
{
	while ((l < r)&&(num[l]!=obj)&&(num[r]!=obj))
	{
		int mid = (l + r) / 2;
	    if (obj <= num[mid])
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	if (num[l] == obj)
		return l;
	if (num[r] == obj)
		return r;
	if (l == r)
		return -1;
}


int quick_sort_test1[100000];
vector<int>quick_sort_test2(1000);
students childs[t_length];
vector<students> childs2(t_length);

int test_sort_search()
{

	genseeds();
	//int n, *num,*num2;
	//cin >> n;
	//num = new int[n];
	//num2 = new int[n];
	//srand((unsigned)time(NULL));
	//for (int i = 0; i < n; i++)
	//{
	//	num[i] = rand()%20;
	//	num2[i] = num[i];
	//}

	//merge_sort(num, 0, n - 1);
	////bubble_sort(num2, 0, n - 1);
	//for (int i = 0; i < n; i++)
	//	cout << num[i] << ' '<<i<<endl;

	//int result=search_iterative(num, 0, n - 1, 15);
	//cout << result;

	//delete[] num;
	//delete[] num2;
	
	for (int i = 0; i < t_length; i++) {
		childs[i].name = genrandstring(1+rand()%20);
		childs2[i].name = childs[i].name;
		childs[i].height = 1 + rand() % 200;
		childs2[i].height = childs[i].height;
	}
	sort(childs2.begin(), childs2.end(), compare_student());
//	T_quick_sort(childs, t_length, compare_student());
	//T_merge_sort(childs, 0, t_length - 1, compare_student());
	bubble_sort(childs, 0, t_length - 1, compare_student());
	for (int i = 0; i < t_length; i++) {
		if (childs[i].name != childs2[i].name|| childs[i].height != childs2[i].height)
			cout << "error: " << childs[i].name << childs[i].height<<' ' << childs2[i].name<<childs2[i].height;
	}
	cout << "over";
	return 0;
}

int algorithm_test() {
	return 0;
}



/*int flag = 1;
	for (int i = 0; i < n; i++)
	{
		if (num[i] != num2[i])
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		cout << "correct";
	else if (flag == 0)
		cout << "incorrect";*/