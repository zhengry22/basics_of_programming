#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<numeric>
#include<cstdlib>
#include<time.h>
#define A 2
#define LEFT 1
#define RIGHT 20000000;
using namespace std;

long long isprime[50000001];
long long primes[50000001];
vector<int> primes_divide;


template<typename T> void my_swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

long long sieve(long long n) {//ɸ����ɸ��n���ڵ�������ע��1�Ƿ�������0������,�����濪��isprime��primes����ʹ��
	long long flag = 0;
	isprime[1] = 1;
	for (int i = 2; i * i <= n; i++) {
		if (isprime[i] == 0) {
			for (int j = i * i; j <= n; j += i) {
				isprime[j] = 1;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (isprime[i] == 0) {
			primes[flag] = i;
			flag++;
		}
	}
	return flag;
}

bool isPrime(long long x) {//�ж�n�ǲ�������
	int sign = true;
	if (x == 1 ||
		(x % 2 == 0 && x != 2)) sign = false;
	for (long long i = 3; i <= sqrt(x); i += 2) {
		if (x % i == 0) {
			sign = false;
			break;
		}
	}
	return sign;
}

long long my_gcd(long long a, long long b) {
	if (a < b) my_swap(a, b);
	while (a != 0) {
		if (a < b) my_swap(a, b);
		a = a % b;
	}
	return b;
}

long long my_lcm(long long a, long long b) {
	return a / my_gcd(a, b) * b;
}

//�������������
void genseeds()
{
	srand(time(0));
}

//���������
//minnum��Сֵ
//maxnum���ֵ
//num����
//numperlineÿ�м�����
void genrandnumber(int minnum, int maxnum, int num, int numperline = 10)
{
	genseeds();
	for (int i = 0; i < num; i++)
	{
		int a = rand() % (maxnum - minnum + 1) + minnum;
		cout << a << (((i + 1) % numperline == 0) ? '\n' : ' ');
		//cout << a+rand() % (maxnum - minnum + 1) + minnum << endl;
	}
}

string genrandstring(int length) {
	//genseeds();
	string all_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string tmp;
	for (int i = 0; i < length; i++) {
		int a = rand() % all_chars.size();
		tmp.push_back(all_chars[a]);
	}
	return tmp;
}

bool ispalin(long long x) {//�ж�x�ǲ��ǻ�����
	long long store = x;
	long long tmp = 0;
	while (x != 0) {
		tmp = (tmp * 10) + (x % 10);
		x /= 10;
	}
	if (tmp == store)return true;
	else return false;
}

template<typename T>
T fast_power(T base, int expo)//�����ݣ�base��expo�η�
{
	if (expo == 0)
		return T(1);
	else {
		if (expo % 2 == 0) {
			base = base * base, expo /= 2;
			return fast_power(base, expo);
		}
		else {
			T base_tmp = base;
			T result = fast_power(base, expo - 1) * base_tmp;
			return result;
		}
	}
}

class science {//��ѧ��������base�ǵף�expo��10��ָ��
private:
	long long base; //
	int exp;
public:
	science operator* (const science a)
	{
		science result;
		result.base = a.base * base;
		result.exp = a.exp + exp;
		while (result.base >= 1000000) {
			result.base /= 10;
			result.exp++;
		}
		return result;
	}

	science(const long long base, const int exp = 0) : base(base), exp(exp) {}

	science() : base(1), exp(0) {}

	void show()
	{
		cout << base << ' ' << exp << endl;
	}
};

void prime_division(long long n) {
	long long sign=sieve(n);
	for (int i = 0; i < sign; i++) {
		while (n % primes[i] == 0) {
			n /= primes[i];
			primes_divide.push_back(primes[i]);
		}
	}
}

