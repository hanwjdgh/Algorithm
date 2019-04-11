#include <iostream>
#include <ios>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int y, x;
};

Node node[82];
int map[9][9], block[3], temp[9][9];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, n_cnt, max_v;

void dfs(int cur, int cnt) {
	if (cnt == 3) {
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				temp[y][x] = map[y][x];

		for (int i = 0; i < 3; i++) {
			int idx = block[i];
			temp[node[idx].y][node[idx].x] = 1;
		}

		int cnt = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (temp[y][x] != 2)
					continue;

				queue <Node > q;
				q.push({ y,x });

				while (!q.empty()) {
					Node cur = q.front();
					q.pop();

					for (int i = 0; i < 4; i++) {
						int ny = cur.y + dir[i][0], nx = cur.x + dir[i][1];

						if (ny < 0 || nx < 0 || ny >= N || nx >= M || temp[ny][nx] != 0)
							continue;
						temp[ny][nx] = 2;
						q.push({ ny,nx });
					}
				}
			}
		}

		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				if (temp[y][x] == 0)
					cnt++;

		max_v = max(max_v, cnt);

		return;
	}

	for (int i = cur; i < n_cnt; i++) {
		block[cnt] = i;
		dfs(i + 1, cnt + 1);
		block[cnt] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			if (map[y][x] == 0) {
				node[n_cnt].y = y, node[n_cnt].x = x;
				n_cnt++;
			}
		}
	}

	dfs(0, 0);

	cout << max_v << "\n";

	return 0;
}