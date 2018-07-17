#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
	int N;

	cin >> N;

	vector <int > dp(N + 1, numeric_limits<int>::max());
	dp[0] = 0;

	for (int i = 1; i*i <= N; i++) {
		for (int j = i*i; j <= N; j++)
			dp[j] = min(dp[j], dp[j-(i*i)]+1);
	}
	cout << dp[N];
	return 0;
}