#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int arr[1001];

int main(void) {
	int num,sum=0,tem=0;
	int a;
	scanf("%d", &num);
	for (a = 0; a < num; a++) {
		scanf("%d", &arr[a]);
	}
	sort(arr, arr + num);
	for (a = 0; a < num; a++) {
		if (a == 0)
			sum = arr[a];
		else {
			sum = sum + arr[a];
		}
		tem += sum;
	}
	printf("%d", tem);
	return 0;
}