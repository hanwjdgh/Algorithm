#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 100001

using namespace std;

typedef pair <int, int > p;

vector < vector <p > > v;
int visit[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, A, B, C;
	int ff, fs, max_v = 0;

	cin >> N >> M;

	v.resize(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		max_v = max(max_v, C);
		v[A].push_back({ B,C });
		v[B].push_back({ A,C });
	}

	cin >> ff >> fs;

	int L = 1, R = max_v;

	while (L <= R) {
		int mid = (L + R) / 2;

		fill(visit, visit + MAX, 0);
		visit[ff] = 1;

		queue <p > q;

		for (auto n : v[ff]) {
			if (n.second >= mid) {
				q.push({ n.first, mid });
				visit[n.first] = 1;
			}
		}

		while (!q.empty()) {
			int cur = q.front().first, val = q.front().second;
			q.pop();

			for (auto n : v[cur]) {
				if (visit[n.first] || n.second < val)
					continue;
				q.push({ n.first, val });
				visit[n.first] = 1;
			}
		}

		if (visit[fs]) 
			L = mid + 1;
		else
			R = mid - 1;
	}

	cout << L - 1 << "\n";

	return 0;
}