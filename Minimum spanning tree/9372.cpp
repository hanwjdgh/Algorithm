#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
	int T;

	cin >> T;
	for (int i = 0; i < T; i++) {
		priority_queue< int, vector<int>, greater<int> > pq;
		int visit[1001] = { 0, };
		int ans = 0;
		int N, M;
		int a, b;

		cin >> N >> M;
		vector<vector<int> > nat(N + 1);

		for (int j = 0; j < M; j++) {
			cin >> a >> b;
			nat[a].push_back(b);
			pq.push(a);
		}

		int start = pq.top();
		pq.pop();
		for (int j = 0; j < nat[start].size(); j++) 
			pq.push(nat[start][j]);
		visit[start] = 1;

		while (!pq.empty()) {
			start = pq.top();
			pq.pop();

			if (visit[start] == 1)
				continue;

			visit[start] = 1;
			ans++;
			for(int j=0; j<nat[start].size();j++)
				pq.push(nat[start][j]);
		}
		printf("%d\n", ans);
	}
	return 0;
}