#include <iostream>
#include <ios>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 802
#define INF 1000000000

using namespace std;

int c[MAX][MAX] = { 0, }, f[MAX][MAX] = { 0, }, co[MAX][MAX] = { 0, };
int pre[MAX], dist[MAX], chk[MAX];
vector <int > adj[MAX];
int S = 0, T = 801;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, si, num, cost;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		adj[S].push_back(i);
		adj[i].push_back(S);
		c[S][i] = 1;
		co[S][i] = co[i][S] = 0;
	}
	for (int i = 1; i <= N; i++) {
		cin >> si;
		for (int j = 0; j < si; j++) {
			cin >> num >> cost;
			adj[i].push_back(num + 400);
			adj[num + 400].push_back(i);
			c[i][num + 400] = 1;
			co[i][num + 400] = cost;
			co[num + 400][i] = -cost;

			adj[num + 400].push_back(T);
			adj[T].push_back(num + 400);
			c[num + 400][T] = 1;
			co[T][num + 400] = co[num + 400][T] = 0;
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