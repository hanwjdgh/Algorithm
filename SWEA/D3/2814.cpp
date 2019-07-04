#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair <int, int > p;

vector <vector <int > > v;
int visit[11], max_v;

void dfs(int cur, int len) {
	max_v = max(max_v, len);
	visit[cur] = 1;
	for (auto n : v[cur]) {
		if (visit[n])
			continue;
		dfs(n, len+1);
	}
	visit[cur] = 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int N, M, a, b;
		fill(visit, visit + 11, 0);
		max_v = 1;

		cin >> N >> M;
		
		v.clear();
		v.resize(N + 1);

		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		
		for (int i = 1; i <= N; i++) {
			fill(visit, visit + 11, 0);
			dfs(i,1);
		}

		cout << "#" << t_case << " " << max_v << "\n";
	}

	return 0;
}
