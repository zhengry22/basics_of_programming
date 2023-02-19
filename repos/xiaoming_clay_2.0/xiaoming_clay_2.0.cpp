#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct clay {
	string color;
	string shape;
};

vector<clay> queue;

template<typename T> void my_swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T, typename U>
void T_quick_sort(vector<T> *p, int n, U rule) {
	if (n <= 1)
		return;
	T t = p[n - 1]; int l = 0, r = n - 2;
	do {
		for (; r >= l; l++)
			if (!rule(p[l], t))
				break;
		for (; r >= l; r--)
			if (rule(p[r], t))
				break;
		if (r >= l)
			my_swap(p[l], p[r]);
	} while (r >= l);
	my_swap(p[l], p[n - 1]);
	T_quick_sort(&p[0], l, rule);
	T_quick_sort(&p[l + 1], n - l - 1, rule);
}


class clay_sort {
public:
	bool operator() (clay a, clay b) {
		return a.color < b.color || (a.color == b.color && a.shape < b.shape);
	}
};

int main() {
	int n; string order;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> order;
		if (order == "CREATE") {
			string cl, sp;
			cin >> cl >> sp;
			queue.push_back({ cl,sp });
		}
		else if (order == "DUP") {
			int num;
			string cl;
			cin >> num; cin >> cl;
			queue.push_back({ cl,queue[num - 1].shape });
		}
		else if (order == "CRASH") {
			int num;
			cin >> num;
			queue.erase(queue.begin() + num - 1);
		}
		else if (order == "ORDER") {
			//sort(queue.begin(), queue.end(), clay_sort());
		//	T_quick_sort(&queue[0], queue.size(), clay_sort());
		}
	}

	for (auto e : queue) {
		cout << e.color << ' ' << e.shape << endl;
	}
	return 0;
}