#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int arr[9];
	int sum = 0, t_a = 0, t_b = 0;

	for (int i = 0; i < 9; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + 9);

	for (int i = 0; i < 9; i++)
		sum += arr[i];

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sum - (arr[i] + arr[j]) == 100) {
				t_a = i;
				t_b = j;
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (i == t_a || i == t_b)
			continue;
		else
			printf("%d\n", arr[i]);
	}
	
	return 0;
}