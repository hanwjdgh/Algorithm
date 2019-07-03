#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int T, N, max_v;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int dp[100001] = { 0, };
		int num[100001] = { 0, };

		cin >> N;

		max_v = -1000;

		for (int i = 1; i <= N; i++)
			cin >> num[i];

		for (int i = 1; i <= N; i++) {
			dp[i] = max(dp[i - 1] + num[i], num[i]);
			max_v = max(max_v, dp[i]);
		}

		cout << "#" << t_case << " " << max_v << "\n";
	}

	return 0;
}