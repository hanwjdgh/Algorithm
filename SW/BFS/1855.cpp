#include <iostream>
#include <ios>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int T, N, num, max_level;
long long ans;
int ac[100001][20];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		queue <int >q;
		vector <int > odr;

		cin >> N;

		ans = 0;
		vector<vector<int> > adj(N + 1);
		vector<int> dis(N + 1, 0);
		max_level = log2(N) + 1;
		memset(ac, 0, sizeof(ac));

		for (int i = 2; i <= N; i++) {
			cin >> num;
			adj[num].push_back(i);
			ac[i][0] = num;
		}

		for (int j = 0; j<max_level - 1; j++)
			for (int i = 2; i <= N; i++)
				if (ac[i][j])
					ac[i][j + 1] = ac[ac[i][j]][j];

		for (int i = 0; i<adj[1].size(); i++)
			q.push(adj[1][i]);

		int next, cur = 1;
		int p1, p2;
		long long res = 0;

		while (!q.empty()) {
			next = q.front();
			q.pop();

			dis[next] = dis[ac[next][0]] + 1;

			p1 = next, p2 = cur;
			int diff = dis[p1] - dis[p2];

			for (int i = 0; diff; i++) {
				if (diff % 2)
					p1 = ac[p1][i];
				diff /= 2;
			}

			if (p1 != p2) {
				for (int i = max_level - 1; i >= 0; i--) {
					if (ac[p1][i] != ac[p2][i]) {
						p1 = ac[p1][i];
						p2 = ac[p2][i];
					}
				}
				p1 = ac[p1][0];
			}

			for (int i = 0; i<adj[next].size(); i++)
				q.push(adj[next][i]);

			ans += dis[cur] + dis[next] - (dis[p1] * 2);
			cur = next;
		}

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}