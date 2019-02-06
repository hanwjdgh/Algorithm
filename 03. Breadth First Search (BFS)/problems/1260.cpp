#include <iostream>
#include <ios>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1001

using namespace std;

vector <vector <int > > v;
int visit[MAX];
int N, M, V;

void dfs(int cur) {
	cout << cur << " ";

	for (auto next : v[cur]) {
		if (!visit[next]) {
			visit[next] = 1;
			dfs(next);
		}
	}
}

void bfs(int cur) {
	queue <int > q;

	q.push(cur);
	visit[cur] = 1;

	while (!q.empty()) {
		int cu = q.front();
		cout << cu << " ";
		q.pop();

		for (auto next : v[cu]) {
			if (!visit[next]) {
				visit[next] = 1;
				q.push(next);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int a, b;

	cin >> N >> M >> V;

	v.resize(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end());

	visit[V] = 1;
	dfs(V);
	cout << "\n";
	fill(visit, visit + MAX, 0);
	bfs(V);
	cout << "\n";
	return 0;
}