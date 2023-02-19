#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
T fast_power(T base, int expo)
{
	if (expo == 0)
		return T(1);
	else {
		if (expo % 2 == 0) {
			base = base*base, expo /= 2;
			return fast_power(base, expo);
		}
		else {
			T base_tmp = base;
			T result = fast_power(base, expo - 1) * base_tmp;
			return result;
		}
	}
}

class science {
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

	 science(const long long base, const int exp=0) : base(base), exp(exp) {}

	 science() : base(1), exp(0) {}

	 void show()
	 {
		 cout << base << ' ' << exp << endl;
	 }
};

int main()
{	
	long long base; int exp, expo;
	cin >> base;
	cin >> exp >> expo;
	science num1(base, exp);
	science num2 = fast_power(num1, expo);
	num2.show();
	return 0;
}