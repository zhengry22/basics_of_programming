#include<iostream>
#include<string>
using namespace std;

struct books {
	string cate;
	string name;
	int exp;
};

books bag[1000]; int flag = 0;

void swap(books* a, books* b) {
	books tmp = *a; *a = *b; *b = tmp;
}

void remove_name(string name) {
	int remove = 0, address;
	for (int j = 0; j < flag; j++) {
		if (bag[j].name == name) {
			remove = 1;
			address = j;
			break;
		}
	}
	if (remove == 1) {
		for (int j = address; j < flag - 1; j++) {
			bag[j] = bag[j + 1];
		}
		bag[flag - 1] = { "","",0 };
		flag--;
	}
}

void bubble_sort(books* num, int l, int r)
{
	for (int i = r - 1; i >= l; i--)
	{
		int flag = 0;
		for (int j = l; j <= i; j++)
		{
			if (num[j].exp >= num[j + 1].exp)
			{
				flag = 1;
				swap(&num[j], &num[j + 1]);
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
} 

void merge_sort(books* num, int l, int r)
{
	int middle = (l + r) / 2, lp = l, rp = middle + 1; books* tmp;
	//when to return 
	if (l == r)
		return;
	//first, merge the left and right part
	merge_sort(num, l, middle);
	merge_sort(num, middle + 1, r);
	//create a new array to dispose number
	tmp = new books[r - l + 1];
	int flag = 0;
	while ((lp <= middle) && (rp <= r))
	{
		if (num[lp].exp <= num[rp].exp)
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
	int n; cin >> n;
	string order;
	for (int i = 0; i < n; i++) {
		cin >> order;
		if (order == "ENLIST") {
			cin >> bag[flag].cate >> bag[flag].name >> bag[flag].exp;
			flag++;
		}
		else if (order == "REMOVE") {
			string tmp_name; 
			cin >> tmp_name;
			remove_name(tmp_name);
		}
		else if (order == "REFINE") {
			string tmp_cate;
			cin >> tmp_cate;
			books ref = {"","",-1};
			int tmp_flag = flag; int if_refine = 0;
			for (int j = 0; j < flag; j++) {
				while(bag[j].cate == tmp_cate) {
					if_refine = 1;
					ref = ref.exp > bag[j].exp ? ref : bag[j];
					for (int k = j; k < flag - 1; k++) {
						bag[k] = bag[k + 1];
					}
					bag[flag - 1] = { "","",0 };
					flag--;
				}
			}
			if (if_refine == 1) { bag[flag] = ref; flag++; }
		}
		else if (order == "CLEANUP") {
			string tmp_cate;
			cin >> tmp_cate;
			int tmp_flag = flag;
			//first remove
			for (int j = 0; j < flag; j++) {
				while (bag[j].cate == tmp_cate) {
					for (int k = j; k < flag - 1; k++) {
						bag[k] = bag[k + 1];
					}
					bag[flag - 1] = { "","",0 };
					flag--;
				}
			}
			//next sort
			merge_sort(bag, 0, flag - 1);
		}
	}
	if (flag == 0) {
		cout << "NULL"<<endl; return 0;
	}
	else if (flag <= 3) {
		for (int i = flag - 1; i >= 0; i--) {
			cout << bag[i].cate << ' ' << bag[i].name << ' ' << bag[i].exp << endl;
		}
		return 0;
	}
	else {
		for (int i = flag - 1; i >= flag - 3; i--) {
			cout << bag[i].cate << ' ' << bag[i].name << ' ' << bag[i].exp << endl;
		}
		return 0;
	}
}