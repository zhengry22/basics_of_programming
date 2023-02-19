#include<iostream>
using namespace std;

int numbers[10000000];

void Qsort(int arr[], int low, int high) {
    if (high <= low) return;
    int i = low;
    int j = high;
    int key = arr[low];
    while (true)
    {
        /*���������ұ�key���ֵ*/
        while (arr[i] <= key)
        {
            i++;
            if (i == high) {
                break;
            }
        }
        /*���������ұ�keyС��ֵ*/
        while (arr[j] >= key)
        {
            j--;
            if (j == low) {
                break;
            }
        }
        if (i >= j) break;
        /*����i,j��Ӧ��ֵ*/
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    /*����ֵ��j��Ӧֵ����*/
    arr[low] = arr[j];
    arr[j] = key;
    Qsort(arr, low, j - 1);
    Qsort(arr, j + 1, high);
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> numbers[i];
	}

}