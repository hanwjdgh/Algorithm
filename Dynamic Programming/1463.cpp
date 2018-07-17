#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int > dp;

int main() {
	int N,num;

	cin >> N;
	
	dp.push_back(0);
	dp.push_back(0);

	for (int i = 2; i <= N; i++) {
		dp.push_back(dp[i - 1] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if(i%2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[N];
	return 0;
}