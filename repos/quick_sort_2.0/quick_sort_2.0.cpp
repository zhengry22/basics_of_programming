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
        /*从左向右找比key大的值*/
        while (arr[i] <= key)
        {
            i++;
            if (i == high) {
                break;
            }
        }
        /*从右向左找比key小的值*/
        while (arr[j] >= key)
        {
            j--;
            if (j == low) {
                break;
            }
        }
        if (i >= j) break;
        /*交换i,j对应的值*/
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    /*中枢值与j对应值交换*/
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