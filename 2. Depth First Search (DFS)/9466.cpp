#include <iostream>
#include <ios>

#define MAX 100001

using namespace std;

int visit[MAX] = { 0, };
int fin[MAX] = { 0, };
int adj[MAX] = { 0, };
int cnt;

void dfs(int u) {
	visit[u] = 1;
	int v = adj[u];
	
	if (!visit[v])
		dfs(v);
	else {
		if (!fin[v]) {
			for (int pre = v; pre != u; pre = adj[pre]) 
				cnt++;
			cnt++;
		}
	}
	fin[u] = 1;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;
	while (T--) {
		fill(adj, adj + MAX, 0);
		fill(visit, visit + MAX, 0);
		fill(fin, fin + MAX, 0);

		cnt = 0;
		int n, num;

		cin >> n;
		for (int i = 1; i <= n; i++) 
			cin >> adj[i];

		for (int i = 1; i <= n; i++) {
			if (!visit[i])
				dfs(i);
		}
		cout << n - cnt << endl;
	}
	return 0;
}