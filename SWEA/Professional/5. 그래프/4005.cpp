#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, K, ans;
int cnt[11], visit[11];
int chk[11][11];
vector <int > adj[11];

void init() {
	ans = 0;
	for (int i = 1; i <= 10; i++)
		cnt[i] = 0;

	for (int i = 0; i < 11; i++)
		adj[i].clear();

	for (int i = 1; i <= 10; i++)
		adj[0].push_back(i);

	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			chk[i][j] = 0;
}

void dfs(int cur, int cnt) {
	ans = max(ans, cnt);

	for (auto& n : adj[cur]) {
		if (visit[n])
			continue;
		visit[n] = 1;
		dfs(n, cnt + 1);
		visit[n] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int num, tmp, idx;

		init();

		cin >> N >> K;

		for (int i = 0; i < K; i++) {
			cin >> num >> tmp;

			for (int j = 0; j < num - 1; j++) {
				cin >> idx;

				if (j < num - 1 && chk[tmp][idx] == 0) {
					cnt[tmp]++;
					adj[tmp].push_back(idx);
					chk[tmp][idx] = 1;
				}
				tmp = idx;
			}
		}

		dfs(0, 0);

		cout << "#" << t_case << " ";

		for (int i = 1; i <= N; i++)
			cout << cnt[i] << " ";
		cout << ans << "\n";
	}
	return 0;
}