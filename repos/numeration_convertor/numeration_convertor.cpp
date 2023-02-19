#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int n,m,p;
	stack<int> conv;
	cout << "enter a decimal number: " << endl;
	cin >> n;
	cout << "convert into which numeration? " << endl;
	cin >> m;
	while (n != 0)
	{
		conv.push(n % m);
		n /= m;
	}
	while (!conv.empty())
	{
		cout << conv.top();
		conv.pop();
	}
	return 0;
}