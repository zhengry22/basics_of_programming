#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct child {
	string name;
	int height;
};
vector<child> que;
void swap(child* a, child* b)
{
	child tmp;
	tmp.height = a->height; tmp.name = a->name;
	a->height = b->height; a->name = b->name;
	b->name = tmp.name; b->height = tmp.height;
}

void bubble_sort(int l, int r)
{
	for (int i = r - 1; i >= l; i--)
	{
		int flag = 0;
		for (int j = l; j <= i; j++)
		{
			if (que[j].height>que[j+1].height||(que[j].height == que[j + 1].height&&que[j].name>que[j+1].name))
			{
				flag = 1;
				swap(&que[j], &que[j + 1]);
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		string order;
		cin >> order;
		if (order == "ADD") {
			string tn;  int h;
			cin >> tn;
			cin>>h;
			que.push_back({ tn, h });
			continue;
		}
		else if (order == "SELECT") {
			string tn; child tmp;
			cin >> tn;
			for (int i = 0; i < que.size();i++) {
				if (que[i].name == tn) {
					tmp.name = tn; tmp.height = que[i].height;
					que.erase(que.begin() + i);
					que.insert(que.begin(), tmp);
					break;
				}
			}
			continue;
		}
		else if (order == "LEAVE") {
			string tn;
			cin >> tn;
			for (int i = 0; i < que.size(); i++) {
				if (que[i].name == tn) {
					que.erase(que.begin() + i);
					break;
				}
			}
			continue;
		}
		else if (order == "ORDER") {
			bubble_sort(0, que.size() - 1);
			continue;
		}
	}

	for (auto e : que) {
		cout << e.name << ' ' << e.height << endl;
	}
	return 0;
}