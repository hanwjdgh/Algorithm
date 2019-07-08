#include <iostream>
#include <ios>
#include <queue>
#include <vector>

using namespace std;

int N, S;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t_case = 1; t_case <= 10; t_case++) {
		int max_v = 0, a, b, ans = 0;
		int visit[101] = { 0, };
		vector <int > adj[101];

		queue <int > q;

		cin >> N >> S;

		for (int i = 0; i < N / 2; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
		}

		visit[S] = 1;
		q.push(S);

		while (!q.empty()) {
			int qs = q.size();
			bool flag = false;

			max_v = 0;

			for (int i = 0; i < qs; i++) {
				int cur = q.front();
				max_v = max(max_v, cur);
				q.pop();

				for (auto n : adj[cur]) {
					if (visit[n])
						continue;

					flag = true;
					q.push(n);
					visit[n] = 1;
				}
			}

			if (!flag)
				ans = max_v;
		}

		cout << "#" << t_case << " " <<  ans << "\n";
	}

	return 0;
}