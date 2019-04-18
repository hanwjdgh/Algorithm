# Quick Sort

It picks an element as pivot and partitions the given array around the picked pivot

Time complexity => best : Θ(nlogn), Avg : Θ(nlogn), Worst : Θ(n<sup>2</sup>)

```bash
#include <iostream>
#include <ios>

using namespace std;

int partition_ASC(int arr[], int left, int right) {
    int pivot = arr[left];
    int low = left + 1;
    int high = right;

    while (low <= high) {
        while (pivot >= arr[low] && low <= right)
            low++;
        while (pivot <= arr[high] && high >= (left + 1))
            high--;
        if (low <= high)
            swap(arr[low], arr[high]);
    }
    swap(arr[left], arr[high]);
    return high;
}

int partition_DESC(int arr[], int left, int right) {
    int pivot = arr[left];
    int low = left + 1;
    int high = right;

    while (low <= high) {
        while (pivot <= arr[low] && low <= right)
            low++;
        while (pivot >= arr[high] && high >= (left + 1))
            high--;
        if (low <= high)
            swap(arr[low], arr[high]);
    }
    swap(arr[left], arr[high]);
    return high;
}

void quickSort_ASC(int arr[], int left, int right) {
    if (left <= right) {
        int pivot = partition_ASC(arr, left, right);
        quickSort_ASC(arr, left, pivot - 1);
        quickSort_ASC(arr, pivot + 1, right);
    }
}

void quickSort_DESC(int arr[], int left, int right) {
    if (left <= right) {
        int pivot = partition_DESC(arr, left, right);
        quickSort_DESC(arr, left, pivot - 1);
        quickSort_DESC(arr, pivot + 1, right);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int arr[5] = { 5,3,2,4,1 };
    int n = sizeof(arr) / sizeof(int);

    quickSort_ASC(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    quickSort_DESC(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}
```