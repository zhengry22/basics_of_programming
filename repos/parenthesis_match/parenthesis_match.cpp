#include<iostream>
#include<map>
#include<set>
#include<stack>
using namespace std;

string formula;
stack<char> pts;
map<char, char> prths = { {')','('} };
set<char> lf = { '(','[','{' };
set<char> rt = { ')',']','}' };

void match()
{
	for (auto it = prths.begin(); it != prths.end(); it++)
	{
		cout << it->second << ' ' << it->first << endl;
	}
	for (char e : formula)
	{
		if (lf.contains(e))
		{
			pts.push(e);
		}
		else if (!pts.empty() && (rt.contains(e)))
			{
				if (pts.top()==prths[e])
				pts.pop();
				else {
				cout << "error: different kinds of parentheses are merged together!!!" << endl;
				return;
				}
			}
		else if (pts.empty() && (rt.contains(e)))
		{
			cout << "error: too much right parentheses!!!" << endl;
			return;
		}
	}
	if (!pts.empty())
	{
		cout << "error: too much left parentheses!!!" << endl;
		return;
	}
	else {
		cout << "correct: parentheses match" << endl;
	}
}

int main()
{
	cin >> formula;
	prths.insert({ ']','[' });
	prths['}']='{';
	match();
	return 0;
}