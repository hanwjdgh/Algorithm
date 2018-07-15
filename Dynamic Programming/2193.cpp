#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n;
	long long arr[91] = { 0,1 };
	scanf("%d", &n);
	for (int a = 2; a < n + 1; a++)
		arr[a] = arr[a - 1] + arr[a - 2];
	printf("%lld", arr[n]);
	return 0;
}