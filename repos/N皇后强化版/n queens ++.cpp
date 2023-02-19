#include <iostream>
using namespace std;


int arr[20], total_cnt;
bool col[20], lef[30], rgt[30];

// arr��¼ÿһ��(X)�ʺ��Y����

bool isPlaceOK(int* a, int n, int c, int x, int y) {
    for (int i = 1; i <= n - 1; ++i) {
        if (a[i] == c || a[i] - i == c - n || a[i] + i == c + n || ((i == x) && (a[i] == y)))
            return false;
        //���λ���Ƿ���Է�
        //c�ǽ�Ҫ���õ�λ��
        //a[i] == c�������ͬһ�У�false
        //a[i] -+ i = c -+ n ����ڶԽ����ϣ�false
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
        if (n > N) { //n����ӵ�һ�п�ʼ����
            total_cnt++;
            return;
        }
        for (int i = 1; i <= N; ++i) { //i�ӵ�1�е���N�б���
            if ((col[i] != 0)||(lef[i-n+N] != 0)||(rgt[i+n-1]!=0))//�����i���Ѿ��������ӣ��Ͳ��ٽ����ӷ����ڵ�i�У�col[i]=1
                continue;
            else if (isPlaceOK(a, n, i, x, y)) {
                a[n] = i; //������Է��ã��Ͱѻʺ���ڵ�n�е�i��
                col[i] = lef[i - n + N]= rgt[i + n - 1]=1;//�����б��
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