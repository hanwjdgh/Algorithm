#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> arr;
int N,S, cnt = 0;

void find(int idx, int sum) {
	if (idx >= N)
		return;
	sum += arr[idx];
	if (sum == S)
		cnt++;
	find(idx + 1, sum - arr[idx]);
	find(idx + 1, sum);
}
int main() {
	int num;
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		arr.push_back(num);
	}
	find(0, 0);
	printf("%d\n", cnt);
	return 0;
}