#include <iostream>
#include <ios>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 202
#define INF 1000000000

using namespace std;

int c[MAX][MAX] = { 0, }, f[MAX][MAX] = { 0, }, co[MAX][MAX] = { 0, };
int pre[MAX], dist[MAX], chk[MAX];
vector <int > adj[MAX];
int S = 0, T = 201;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, si, num, cost;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		c[i + 100][T] = num;
		co[i + 100][T] = co[T][i + 100] = 0;
		adj[i + 100].push_back(T);
		adj[T].push_back(i + 100);
	}

	for (int i = 1; i <= M; i++) {
		cin >> num;
		c[S][i] = num;
		co[i][S] = co[S][i] = 0;
		adj[i].push_back(S);
		adj[S].push_back(i);
	}
	
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num;
			adj[i].push_back(j + 100);
			adj[j + 100].push_back(i);
			c[i][j + 100] = num;
		}
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num;
			co[i][j + 100] = num;
			co[j + 100][i] = -num;
		}
	}

	int ans = 0, cnt = 0;
	while (1) {
		fill(pre, pre + MAX, -1);
		fill(dist, dist + MAX, INF);
		fill(chk, chk + MAX, 0);

		queue <int > q;
		q.push(S);
		dist[S] = 0;
		chk[S] = 1;

		while (!q.empty()) {
			int x = q.front();
			q.pop();
			chk[x] = 0;
			for (int y : adj[x]) {
				if (c[x][y] - f[x][y] > 0 && dist[y] > dist[x] + co[x][y]) {
					dist[y] = dist[x] + co[x][y];
					pre[y] = x;
					if (!chk[y]) {
						chk[y] = 1;
						q.push(y);
					}
				}
			}
		}
		
		if (pre[T] == -1)
			break;

		for (int i = T; i != S; i = pre[i]) {
			ans += co[pre[i]][i];
			f[pre[i]][i]++;
			f[i][pre[i]]--;
		}
		cnt++;
	}
	cout << cnt << "\n";
	cout << ans << "\n";
	return 0;
}