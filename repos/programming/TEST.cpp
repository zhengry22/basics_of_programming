#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<cmath>
#include<numeric>
#include<cstdlib>
#include<time.h>
#include<string>
#include"my_MATH.h"
#include"sort_search.h"
#include"string_operation.h"
#define arr_length 100
#define mod 20
using namespace std;

extern vector<int> primes_divide;
extern long long isprime[50000001];
extern long long primes[50000001];

void test_my_gcd() {
	genseeds();
	for (int i = 1; i <= 100000; i++) {
		int tmp1 = 1 + rand() % 2000, tmp2 = 1 + rand() % 2000, tmp3;
		/*if (gcd(tmp1, tmp2) != (tmp3 = my_gcd(tmp1, tmp2))) {
			cout << "error" << ' ' << tmp1 << ' ' << tmp2 << endl;
		}
		else {
			cout << tmp1 << ' ' << tmp2 << ' ' << tmp3 << endl;
		}*/
	}
}



void test_fast_power() {
	cout<<fast_power((long long)3, 37)<<endl;
	cout << fast_power(1.5, 2)<<endl;
	science sc_test(250, 8);
	fast_power(sc_test, 10).show();
}

void test_prime_division() {
	for (int i = 2; i <= 1000; i++) {
		prime_division(i);
		for (auto e : primes_divide) {
			cout << e << ' ';
		}
		cout << endl;
		primes_divide.clear();
	}
	cout << "over";
}

int main() {
	//test_my_gcd();
	//test_fast_power();
	//test_prime_division();
	/*int arr[arr_length];
	genseeds();*/
	/*vector<int> t(5,10);
	vector<int> t2,t3;
	t.insert(t.begin(), 7);
	t.insert(t.begin() + 1, 8);
	t.insert(t.begin() + 3, 9);
	t.erase(t.begin() + 2);
	t.resize(3);
	t2 = t;
	t3.insert(t3.begin(), 1);
	t3.resize(10);
	copy(t2.begin()+1, t2.begin()+3, t3.begin() + 1);
	
	t2.swap(t3);*/


	/*for (int i = 0; i < arr_length; i++) {
		arr[i] = rand() % mod + 1;
	}
	sort(arr, arr + arr_length);
	bool tmp=binary_search(arr, arr + arr_length, 10);
	auto lower_b = lower_bound(arr, arr + arr_length, 10);
	auto upper_b = upper_bound(arr, arr + arr_length, 10);
	cout << (tmp ? "true" : "false")<<endl;
	cout << lower_b-arr<<endl;
	cout << upper_b-arr-1<<endl;
	cout<<count(arr, arr + arr_length, 10)<<endl;
	cout << count_if(arr, arr + arr_length, [](int i) {return i <= 5; });
	if (find(arr, arr + arr_length, 50) != arr + arr_length) {
		cout << 50 << " was found";
	}
	else cout << 50 << "  was not found";*/
	/*for (const auto &e : t2) {
		cout << e << ' ';
	}
	cout << "t2";
	for (const auto& e : t3) {
		cout << e<<' ';
	}
	cout << "t3";*/
	//test_sort_search();
	//cout << "over";

	/*vector<string> to; vector<long long> datastore;
	string split = "-:, ";
	string st = "2022-2-18,11:30";
	strsplit(st, split, to);
	for (auto& e : to) {
		datastore.push_back(stol(e));
		cout << e << endl;
	}
	for (auto& e : datastore) {
		cout << e * 2 << endl;
	}*/


	/*string t1 = "example";
	string t2(t1, 1, t1.size());
	cout << t2;*/

	//string t3 = "my name is peter, hello";
	string t4; getline(cin, t4);
	//cout << t4;

	//vector<string> to; vector<long long> datastore;
	//string split = "-:, ";
	////string st = "2022-2-18,11:30";
	//strsplit(t4, split, to);
	//for (auto& e : to) {
	//	cout << e << endl;
	//}
	/*for (auto& e : datastore) {
		cout << e * 2 << endl;
	}*/
	sort(t4.begin(), t4.end());
	for (auto e : t4) {
		cout << e;
	}
	cout << endl;
	cout<<count(t4.begin(), t4.end(),'e')<<endl;
	cout<<count_if(t4.begin(), t4.end(), [](char a) {return( a >= 'a') &&( a <= 'm'); });
	return 0;

}