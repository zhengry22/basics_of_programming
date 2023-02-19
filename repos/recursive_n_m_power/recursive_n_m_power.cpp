#include<iostream>
#include<cstring>
using namespace std;

struct science {
	double base;
	int expo;
};

double base[100001];
int exponent[100001];
science numbers[1000001];

science fast_power_top(science number, int exponent, int i)
{
	if (exponent <= 1)
		return number;
	else {
		if (exponent % 2 == 0){
			number.base *= number.base, number.expo *= 2, exponent/=2;
			if (number.base >= 10)
			{
				number.base /= 10;
				number.expo++;
			}
			return fast_power_top(number, exponent, i);
		}
		else {
			science tmp = { number.base * fast_power_top(number, exponent - 1, i).base, number.expo + fast_power_top(number, exponent - 1, i).expo };
			if (tmp.base >= 10) { tmp.base /= 10, tmp.expo++; }
			return tmp;
		}
	}	
} 

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> base[i] >> exponent[i];
	}
	//acquire base and expo
	for (int i = 1; i <= t; i++)
	{
		science result;
		numbers[i].base = base[i];
		while (numbers[i].base >= 10)
		{
			numbers[i].base /= 10, numbers[i].expo++;
		}
		result=fast_power_top(numbers[i], exponent[i], i);
		
		if (result.expo < 2){
			int ex=1;
			for (int i = 0; i < 2 - i; i++)
				cout << '0';
			for (int i = 1; i <= result.expo; i++)
				ex *= 10;
			cout << (int)(result.base * ex) << endl;
		}
		else
			cout << (int)(result.base*100)<<endl;

	}
	return 0;
}