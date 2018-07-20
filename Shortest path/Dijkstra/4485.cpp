#include <iostream>
#include <cstdio>
#include <queue>
#include <functional>
#include <tuple>

using namespace std;

typedef tuple <int, int, int> t;

tuple <int, int, int> tmp;

int main() {
	int N,cnt=1;
	int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

	while (1) {
		int maze[126][126];
		int visit[126][126] = { 0, };
		priority_queue< t, vector<t>, greater<t> > pq;

		cin >> N;
		if (!N)
			break;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> maze[i][j];

		pq.push(make_tuple(maze[0][0], 0, 0));
		visit[0][0] = 1;
		while (!pq.empty()) {
			tmp = pq.top();
			pq.pop();
			int x, y, cost;
			cost = get<0>(tmp), x = get<1>(tmp), y = get<2>(tmp);
			if (x == N - 1 && y == N - 1) {
				printf("Problem %d: %d\n", cnt++, cost);
				break;
			}

			int mx, my, mcost;
			for (int i = 0; i < 4; i++) {
				mx = x + dx[i], my = y + dy[i];
				mcost = cost + maze[mx][my];
				if (mx < 0 || mx >= N || my < 0 || my >= N || visit[mx][my] == 1)
					continue;
				visit[mx][my] = 1;
				pq.push(make_tuple(mcost, mx, my));
			}
		}
	}
	return 0;
}