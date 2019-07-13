#include <iostream>
#include <ios>

#define INF 987654321

using namespace std;

int T, N, M, ans;
int graph[501][501];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int a, b;
		ans = 0;

		cin >> N >> M;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				graph[i][j] = (i == j ? 0 : INF);
			}
		}

		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			graph[a][b] = 1;
		}

		for (int k = 1; k <= N; ++k) {
			for (int i = 1; i <= N; ++i) {
				for (int j = 1; j <= N; ++j) {
					if (graph[i][j] > graph[i][k] + graph[k][j])
						graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}

		for (int i = 1; i <= N; i++) {

			bool err = false;
			for (int j = 1; j <= N; j++) {
				if (graph[i][j] == INF && graph[j][i] == INF) {
					err = true;
					break;
				}
			}

			if (!err)
				ans++;
		}

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}