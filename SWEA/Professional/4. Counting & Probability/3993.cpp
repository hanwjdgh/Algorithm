#include <iostream>
#include <ios>

using namespace std;

int T, N, L, R;
long long dp[21][21][21];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	dp[1][1][1] = 1;

	for (int n = 2; n <= 20; n++) {
		for (int l = 1; l <= 20; l++) {
			for (int r = 1; r <= 20; r++) {
				dp[n][l][r] = dp[n - 1][l - 1][r] + dp[n - 1][l][r - 1] + (n - 2) * dp[n - 1][r][l];
			}
		}
	}

	for (int t_case = 1; t_case <= T; t_case++) {

		cin >> N >> L >> R;

		cout << "#" << t_case << " " << dp[N][L][R] << "\n";
	}

	return 0;
}