#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int board[21];
int T, N, M;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int ans = 0, max_v = -1;
		int temp;

		cin >> N >> M;

		for (int y = 0; y < N; y++) {
			int cnt = 0;
			for (int x = 0; x < M; x++) {
				cin >> temp;

				if (temp == 1)
					cnt++;
			}

			board[y] = cnt;
			max_v = max(max_v, cnt);
		}

		for (int i = 0; i < N; i++) {
			if (board[i] == max_v)
				ans++;
		}

		cout << "#" << t_case << " " << ans << " " << max_v << "\n";
	}

	return 0;
}