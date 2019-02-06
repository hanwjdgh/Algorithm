#include <iostream>
#include <ios>
#include <queue>
#include <vector>

#define MAX 20001

using namespace std;

vector <vector <int > > v;
int visit[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int K, V, E;
	int a, b;

	cin >> K;

	for (int i = 0; i < K; i++) {
		bool chk = true;

		cin >> V >> E;

		v.clear();
		v.resize(V + 1);
		fill(visit, visit + MAX, 0);
		
		for (int j = 0; j < E; j++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int j = 1; j <= V; j++) {
			if (!chk)
				break;

			if (visit[j] == 0) {
				queue <int > q;
				q.push(j);
				visit[j] = 1;

				while (!q.empty()) {
					int cur = q.front();
					q.pop();

					for (auto next : v[cur]) {
						if (visit[next] == 0) {
							q.push(next);
							visit[next] = visit[cur] * -1;
						}
						else if (visit[cur] + visit[next] != 0) {
							chk = false;
							break;
						}
					}

				}
			}
		}
		
		if (chk)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}