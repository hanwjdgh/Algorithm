#include <iostream>
#include <cstdio>
#include <queue>
#include <functional>
#include <tuple>

using namespace std;

typedef tuple <int, int, int> t;

priority_queue< t, vector<t>, greater<t> > pq;
tuple <int, int, int> tmp;

int main() {
	int N, M;
	char maze[101][101];
	int visit[101][101] = { 0, };
	int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

	cin >> M >> N;
	for (int i = 0; i < N; i++)
		cin >> maze[i];

	pq.push(make_tuple(0, 0, 0));
	visit[0][0] = 1;
	while (!pq.empty()) {
		tmp = pq.top();
		pq.pop();
		int x, y, cost;
		cost = get<0>(tmp), x = get<1>(tmp), y = get<2>(tmp);
		if (x == N - 1 && y == M - 1) {
			printf("%d", cost);
			break;
		}

		int mx, my, mcost;
		for (int i = 0; i < 4; i++) {
			mx = x + dx[i], my = y + dy[i];
			mcost = cost + (maze[mx][my] - '0');
			if (mx < 0 || mx >= N || my < 0 || my >= M || visit[mx][my] == 1)
				continue;
			visit[mx][my] = 1;
			pq.push(make_tuple(mcost, mx, my));
		}
	}
	return 0;
}