#include<iostream>
using namespace std;

struct goods {
	int number;
	int origin;
	int on_sale;
	float actual;
	float save;
};

goods buy[1001]; 
int shop_cart[1001];

void merge_sort_goods(goods* num, int l, int r)
{
	int middle = (l + r) / 2, lp = l, rp = middle + 1; goods* tmp;
	//when to return 
	if (l == r)
		return;
	//first, merge the left and right part
	merge_sort_goods(num, l, middle);
	merge_sort_goods(num, middle + 1, r);
	//create a new array to dispose number
	tmp = new goods[r - l + 1];
	int flag = 0;
	while ((lp <= middle) && (rp <= r))
	{
		if (num[lp].save > num[rp].save||(num[lp].save == num[rp].save&& num[lp].actual < num[rp].actual)||(num[lp].save == num[rp].save && num[lp].actual == num[rp].actual&&num[lp].number<num[rp].number))
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

void merge_sort(int* num, int l, int r)
{
	int middle = (l + r) / 2, * tmp, lp = l, rp = middle + 1;
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
	for (int i = 0, j = l; i < r - l + 1; i++, j++)
	{
		num[j] = tmp[i];
	}
	delete[] tmp;
}


int main() {
	float money; int n,flag=0;
	cin >> money >> n;
	for (int i = 1; i <= n; i++) {
		cin >> buy[i].origin >> buy[i].on_sale;
	}
	for (int i = 1; i <= n; i++) {
		buy[i].number = i;
		if (buy[i].on_sale == 1) {
			buy[i].actual = (float)buy[i].origin / 2;
			buy[i].save = (float)buy[i].origin / 2;
		}
		else {
			buy[i].actual = (float)buy[i].origin;
		}
	}
	merge_sort_goods(buy, 1, n);
	int if_buy = 0;
	for (int i = 1; i <= n; i++) {
		if (buy[i].actual <= money) {
			if_buy = 1;
			shop_cart[flag] = buy[i].number;
			flag++;
			money -= buy[i].actual;
		}
	}
	if (if_buy == 0) { cout << 0; return 0;}
	merge_sort(shop_cart, 0, flag - 1);
	for (int i = 0; i < flag-1; i++) {
		cout << shop_cart[i] << ' ';
	}
	cout << shop_cart[flag - 1]; return 0;
}