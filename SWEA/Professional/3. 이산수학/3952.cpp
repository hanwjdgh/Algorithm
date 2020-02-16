#include <iostream>
#include <ios>
#include <queue>
#include <vector>

using namespace std;

int T, N, M, a, b;
int line[50001], ans[50001];
vector <int > adj[50001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {

		queue <int > q;

		cin >> N >> M;

		for (int i = 1; i <= N; i++) {
			line[i] = ans[i] = 0;
			adj[i].clear();
		}

		for (int i = 0; i < M; i++) {
			cin >> a >> b;

			line[b]++;
			adj[a].push_back(b);
		}
		
		for (int i = 1; i <= N; i++) {
			if (line[i] == 0)
				q.push(i);
		}

		for (int i = 0; i < N; i++) {
			if (q.empty())
				break;
			
			int cur = q.front();
			q.pop();

			ans[i] = cur;

			for (auto& n : adj[cur]) {
				if (--line[n] == 0)
					q.push(n);
			}
		}
		

		cout << "#" << t_case << " ";

		for (int i = 0; i < N; i++)
			cout << ans[i] << " ";

		cout << "\n";
	}
	return 0;
}