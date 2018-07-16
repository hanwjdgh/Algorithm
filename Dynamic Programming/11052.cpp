#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int > arr;

int main() {
	int N,num;

	cin >> N;

	vector <int > dp(N + 1, 0);
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	for (int i = 0; i < N; i++) {
		int val = arr[i];
		for (int j = i; j < N; j++) {
			dp[j + 1] = max(dp[j + 1], dp[j + 1 - (i + 1)] + val);
		}
	}
	cout << dp[N];
	return 0;
}