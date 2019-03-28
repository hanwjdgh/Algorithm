#include <iostream>
#include <ios>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int y, x, val;
};

Node node;
int map[16][13], temp[16][13];
int visit[13];
int N, W, H, min_v;
int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };

int find_idx(int x) {
	for (int i = 0; i < H; i++)
		if (temp[i][x] != 0)
			return i;

	return -1;
}

void convert() {
	for (int y = H - 1; y > -1; y--) {
		for (int x = 0; x < W; x++) {
			if (temp[y][x] == 0)
				continue;

			int a = y, b = x;
			for (int k = y + 1; k < H; k++)
				if (temp[k][x] == 0)
					a = k, b = x;
			swap(temp[y][x], temp[a][b]);
		}
	}
}

void dfs(int cur, int cnt) {
	if (cnt == N) {
		if (min_v != 0) {
			for (int y = 0; y < H; y++)
				for (int x = 0; x < W; x++)
					temp[y][x] = map[y][x];

			for (int i = 0; i < N; i++) {
				int idx = find_idx(visit[i]);
				if (idx == -1)
					continue;

				node.y = idx, node.x = visit[i], node.val = temp[idx][visit[i]];
				queue <Node > q;
				q.push(node);

				while (!q.empty()) {
					int cy = q.front().y, cx = q.front().x, cval = q.front().val;
					q.pop();
					temp[cy][cx] = 0;

					for (int j = 1; j <= cval - 1; j++) {
						for (int k = 0; k < 4; k++) {
							Node next;
							int ny = cy + dir[k][0] * j, nx = cx + dir[k][1] * j;
							if (ny < 0 || nx < 0 || ny >= H || nx >= W || temp[ny][nx] == 0)
								continue;
							next.y = ny, next.x = nx, next.val = temp[ny][nx];
							q.push(next);
						}
					}
				}

				convert();
			}

			int cnt = 0;
			for (int y = 0; y < H; y++)
				for (int x = 0; x < W; x++)
					if (temp[y][x] != 0)
						cnt++;
			min_v = min(min_v, cnt);
		}
		return;
	}

	for (int i = 0; i < W; i++) {
		visit[cnt] = i;
		dfs(i, cnt + 1);
		visit[cnt] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		min_v = 181;

		cin >> N >> W >> H;

		for (int y = 0; y < H; y++)
			for (int x = 0; x < W; x++)
				cin >> map[y][x];

		dfs(0, 0);

		cout << "#" << t << " " << min_v << "\n";
	}

	return 0;
}