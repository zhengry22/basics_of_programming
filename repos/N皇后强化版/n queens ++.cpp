#include <iostream>
using namespace std;


int arr[20], total_cnt;
bool col[20], lef[30], rgt[30];

// arr记录每一行(X)皇后的Y坐标

bool isPlaceOK(int* a, int n, int c, int x, int y) {
    for (int i = 1; i <= n - 1; ++i) {
        if (a[i] == c || a[i] - i == c - n || a[i] + i == c + n || ((i == x) && (a[i] == y)))
            return false;
        //检查位置是否可以放
        //c是将要放置的位置
        //a[i] == c如果放在同一列，false
        //a[i] -+ i = c -+ n 如果在对角线上，false
    }
    return true;
}

void addQueen(int* a, int n, int N, int x, int y) {
    if (N == 1)
    {
        if ((x == 1) && (y == 1))
            total_cnt = 0;
        return;
    }
    else
    {
        if (n > N) { //n代表从第一行开始放置
            total_cnt++;
            return;
        }
        for (int i = 1; i <= N; ++i) { //i从第1列到第N列遍历
            if ((col[i] != 0)||(lef[i-n+N] != 0)||(rgt[i+n-1]!=0))//如果第i列已经有了棋子，就不再将棋子放置于第i列，col[i]=1
                continue;
            else if (isPlaceOK(a, n, i, x, y)) {
                a[n] = i; //如果可以放置，就把皇后放在第n行第i列
                col[i] = lef[i - n + N]= rgt[i + n - 1]=1;//将这列标记
                addQueen(a, n + 1, N, x, y);
                col[i] = lef[i - n + N] = rgt[i + n - 1] = 0;
            }
        }
    }
}

int main() {
    int N, x, y;
    cin >> N >> x >> y;
    addQueen(arr, 1, N, x, y);
    cout << total_cnt;
    return 0;
}