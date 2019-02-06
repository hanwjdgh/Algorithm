#include <iostream>
#include <ios>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1001

using namespace std;

vector <vector< int > > v;
int visit[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int a, b, cnt = 0;

	cin >> N >> M;

	v.resize(N + 1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end());

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			cnt++;
			queue <int > q;

			q.push(i);
			visit[i] = 1;

			while (!q.empty()) {
				int cur = q.front();
				q.pop();

				for (auto next : v[cur]) {
					if (!visit[next]) {
						q.push(next);
						visit[next] = 1;
					}
				}
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}