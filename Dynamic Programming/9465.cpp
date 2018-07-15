#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T, N, num;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;

		vector <vector<int> > dp(2, vector<int>(N, 0)), arr;
		vector <int >tmp;
		for (int j = 1; j <= 2 * N; j++) {
			cin >> num;
			tmp.push_back(num);
			if (j%N == 0) {
				arr.push_back(tmp);
				tmp.clear();
			}
		}

		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[0][1] + dp[1][0];
		dp[1][1] = arr[1][1] + dp[0][0];

		for (int a = 2; a < N; a++) {
			dp[0][a] = max(dp[1][a - 2], dp[1][a - 1]) + arr[0][a];
			dp[1][a] = max(dp[0][a - 2], dp[0][a - 1]) + arr[1][a];
		}
		printf("%d\n", max(dp[0][N-1],dp[1][N-1]));
	}
	return 0;
}