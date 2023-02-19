#include<iostream>
#include<vector>
using namespace std;

vector<int> out_set;

void subset(vector<int> fset, int lev, bool type)
{
	
	if (lev >= fset.size()-1)//leaves
	{
		if (type)
		{
			out_set.push_back(fset[lev]);
		}
		for (auto e : out_set)
		{
			cout << e;
		}
		if (!out_set.empty())
			out_set.pop_back();
		else
			return;
		cout << endl;
		return;
	}
	if (type)
	{
		out_set.push_back(fset[lev]);
	}
	subset(fset, lev + 1, true);
	subset(fset, lev + 1, false);	
}

int main()
{
	int n;
	cin >> n;
	vector<int> full_set(n);
	for (int i=0; i<full_set.size();i++)
	{
		cin >> full_set[i];
	}
	subset(full_set, 0, true);
	subset(full_set, 0, false);
	return 0;
}