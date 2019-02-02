#include <iostream>
#include <ios>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

#define MAX 100001

using namespace std;

vector <vector <int > > v;
int visit[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue <int, vector<int >, greater<int > > pq;
	int n, m, a, b;

	cin >> n >> m;

	v.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	pq.push(1);
	visit[1] = 1;

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();

		cout << cur << " ";

		for (auto next : v[cur]) {
			if (!visit[next]) {
				visit[next] = 1;
				pq.push(next);
			}
		}
	}

	cout << "\n";

	return 0;
}