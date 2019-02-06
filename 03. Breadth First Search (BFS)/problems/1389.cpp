#include <iostream>
#include <ios>
#include <vector>
#include <queue>

#define MAX 5001

using namespace std;

typedef pair <int, int > p;

int visit[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int a, b;
	int idx = 0, min_v = 0, sum = 0;
	vector < vector <int > > v;

	cin >> N >> M;

	v.resize(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		sum = 0;
		queue <p > q;
		fill(visit, visit + MAX, 0);

		q.push({ i,0 });
		visit[i] = 1;

		while (!q.empty()) {
			int cur = q.front().first, cnt = q.front().second;
			q.pop();
			sum += cnt;

			for (auto next : v[cur]) {
				if (visit[next])
					continue;
				q.push({ next,cnt + 1 });
				visit[next] = 1;
			}
		}

		if (min_v == 0 || min_v > sum) {
			idx = i;
			min_v = sum;
		}
	}
	cout << idx << "\n";
	return 0;
}