#include <iostream>
#include <ios>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair <int, int > p;

vector <int > v;
int map[16][13], tmp[16][13];
int N, W, H, min_v = 181;
int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };

int find_idx(int y) {
	for (int i = 0; i < H; i++)
		if (tmp[i][y] != 0)
			return i;

	return -1;
}

void bfs(int x, int y) {
	if (tmp[x][y] == 1)
		tmp[x][y] = 0;
	else {
		queue <p > q;
		q.push({ x,y });

		while (!q.empty()) {
			int cx = q.front().first, cy = q.front().second;
			q.pop();
			int t = tmp[cx][cy];

			tmp[cx][cy] = 0;
			for (int i = 1; i <= t - 1; i++) {
				for (int j = 0; j < 4; j++) {
					int nx = cx + dir[j][0] * i, ny = cy + dir[j][1] * i;

					if (nx < 0 || ny < 0 || nx >= H || ny >= W || tmp[nx][ny] == 0)
						continue;

					if (tmp[nx][ny] != 1)
						q.push({ nx,ny });
					else
						tmp[nx][ny] = 0;
				}
			}
		}
	}
}

void convert() {
	for (int i = H - 1; i > -1; i--) {
		for (int j = 0; j < W; j++) {
			if (tmp[i][j] == 0)
				continue;

			int a = i, b = j;
			for (int k = i + 1; k < H; k++)
				if (tmp[k][j] == 0) {
					a = k, b = j;
				}
			swap(tmp[i][j], tmp[a][b]);
		}
	}
}

void find(int cnt) {
	if (cnt == N) {
		if (min_v != 0) {
			for (int i = 0; i < H; i++)
				for (int j = 0; j < W; j++)
					tmp[i][j] = map[i][j];

			for (int i = 0; i < N; i++) {
				int idx = find_idx(v[i]);
				if (idx == -1)
					continue;

				bfs(idx, v[i]);
				convert();
			}
			int cnt = 0;

			for (int i = 0; i < H; i++)
				for (int j = 0; j < W; j++)
					if (tmp[i][j] != 0)
						cnt++;

			min_v = min(min_v, cnt);
		}
		return;
	}

	for (int i = 0; i < W; i++) {
		v.push_back(i);
		find(cnt + 1);
		v.pop_back();
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		memset(map, 0, sizeof(map));
		memset(tmp, 0, sizeof(tmp));
		v.clear();
		min_v = 181;

		cin >> N >> W >> H;

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				cin >> map[i][j];

		find(0);

		cout << "#" << t << " " << min_v << "\n";
	}

	return 0;
}