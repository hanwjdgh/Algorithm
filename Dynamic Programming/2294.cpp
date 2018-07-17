#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

vector <int > coin;

int main() {
	int n, k, num;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num;
		coin.push_back(num);
	}

	vector <int > dp(k + 1, numeric_limits<int>::max());
	dp[0] = 0;
	sort(coin.begin(), coin.end());

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			if (dp[j - coin[i]] == numeric_limits<int>::max())
				continue;
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	if (dp[k] == numeric_limits<int>::max())
		cout << "-1";
	else
		cout << dp[k];
	return 0;
}