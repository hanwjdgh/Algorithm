#include <iostream>
#include <ios>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX 301
#define INF 1000000000

using namespace std;

int ca[MAX][MAX] = { 0, }, f[MAX][MAX] = { 0, }, d[MAX];
int ct[MAX][MAX] = { 0, }, chk[MAX][MAX] = { 0, };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int K;

	cin >> K;
	while (K--) {
		memset(ca, 0, sizeof(ca));
		memset(f, 0, sizeof(f));
		memset(ct, 0, sizeof(ct));
		memset(chk, 0, sizeof(chk));
		int N, M;
		vector <int > adj[MAX], uv[MAX];

		cin >> N >> M;
		while (M--) {
			int a, b, c;
			cin >> a >> b >> c;
			
			if (chk[a][b] == 0) {
				uv[a].push_back(b);
				chk[a][b] = 1;
			}
			else
				chk[a][b] += 1;
			adj[a].push_back(b);
			adj[b].push_back(a);		
			ca[a][b] += c;
		}

		while (1) {
			fill(d, d + MAX, -1);
			queue <int > q;
			q.push(1);

			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				for (int next : adj[cur]) {
					if (ca[cur][next] - f[cur][next] > 0 && d[next] == -1) {
						q.push(next);
						d[next] = cur;
						if (next == N)
							break;
					}
				}
			}
			if (d[N] == -1)
				break;

			int flow = INF;
			for (int i = N; i != 1; i = d[i])
				flow = min(flow, ca[d[i]][i] - f[d[i]][i]);

			for (int i = N; i != 1; i = d[i]) {
				f[d[i]][i] += flow;
				f[i][d[i]] -= flow;
			}
		}

		int cnt = 0;
		for (int i = 1; i < N; i++) {
			for (int j : uv[i]) {
				if (ca[i][j] > f[i][j])
					continue;

				fill(d, d + MAX, -1);

				queue <int > q;
				q.push(i);

				while (!q.empty()) {
					int cur = q.front();
					q.pop();
					for (int next : adj[cur]) {
						if (ca[cur][next] - f[cur][next] > 0 && d[next] == -1) {
							q.push(next);
							d[next] = cur;
							if (next == j)
								break;
						}
					}
				}
				if (d[j] == -1)
					cnt+=chk[i][j];
			}
		}
		cout << cnt << endl;
	}
	return 0;
}