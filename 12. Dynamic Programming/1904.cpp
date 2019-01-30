#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int > dp;

int main() {
	int N,num;

	cin >> N;

	dp.push_back(1);
	dp.push_back(2);

	if (N == 1)
		cout << dp[N - 1];
	else {
		for (int i = 2; i < N; i++) {
			dp.push_back((dp[i-2]+dp[i-1])% 15746);
		}
		cout << dp[N - 1];
	}
	return 0;
}