#include <iostream>
#include <ios>

#define INF 987654321

using namespace std;

int T, N, ans;
int score[101], visit[101];
int dp[10001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int sum = 0;
		ans = 0;

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> score[i];
			sum += score[i];
		}
		
		dp[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = sum; j > -1; j--) {
				if (dp[j])
					dp[j + score[i]] = 1;
			}
		}

		for (int i = 0; i <= sum; i++)
			if (dp[i])
				ans++;

		cout << "#" << t_case << " " << ans << "\n";

		for (int i = 0; i <= sum; i++)
			dp[i] = 0;

	}

	return 0;
}