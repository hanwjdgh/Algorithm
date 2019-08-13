#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int T, ans, N, M, max_v;
int score[21][21];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int cnt[21] = { 0, };
		ans = max_v = 0;

		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> score[i][j];

				if (score[i][j] == 1)
					cnt[i]++;
			}
		}

		for (int i = 0; i < N; i++)
			max_v = max(max_v, cnt[i]);

		cout << "#" << t_case << " ";

		for (int i = 0; i < N; i++) {
			if (cnt[i] == max_v)
				ans++;
		}

		cout << ans << " " << max_v << "\n";

	}

	return 0;
}