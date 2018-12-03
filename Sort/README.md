# Sort

## 1.Bubble sort

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements

Time complexity => best : Θ(n), worst : Θ(n<sup>2</sup>)

```bash
#include <iostream>
#include <ios>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int arr[5] = { 5,3,2,4,1 };
    int n = sizeof(arr) / sizeof(int);

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << "\n";

    return 0;
}
```
(n-1) + (n-2) + … + 1 = n(n-1)/2 = Θ(n<sup>2</sup>)