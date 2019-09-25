#include <iostream>
#include <ios>
#include <queue>

using namespace std;

struct Node {
	int y, x;
};

bool operator<(Node a, Node b) {
	return (a.x> b.x);
}

int N, M, inum, ans;
int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
int map[101][101], visit[101][101];
int cnt[6], dis[7][7], chk[7];
Node node[6][10001];
priority_queue <Node > pq;

void find(int cy, int cx, int d, int cval, int size) {
	int ny = cy + dir[d][0], nx = cx + dir[d][1];

	if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == cval)
		return;

	if (map[ny][nx] != 0) {
		if (size > 1) {
			if (dis[cval][map[ny][nx]] == 0 || dis[cval][map[ny][nx]] > size) {
				dis[cval][map[ny][nx]] = dis[map[ny][nx]][cval] = size;
			}
		}
		return;
	}

	find(ny, nx, d, cval, size + 1);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> map[y][x];

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (!map[y][x] || visit[y][x])
				continue;

			inum++;
			queue <Node > q;

			q.push({ y,x });
			visit[y][x] = 1;
			map[y][x] = inum;

			node[inum - 1][cnt[inum - 1]].y = y, node[inum - 1][cnt[inum - 1]++].x = x;

			while (!q.empty()) {
				Node cur = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int ny = cur.y + dir[k][0], nx = cur.x + dir[k][1];
					if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx] || map[ny][nx] == 0)
						continue;

					q.push({ ny, nx });
					visit[ny][nx] = 1;
					node[inum - 1][cnt[inum - 1]].y = ny, node[inum - 1][cnt[inum - 1]++].x = nx;
					map[ny][nx] = inum;
				}
			}
		}
	}

	for (int i = 0; i < inum; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			int cy = node[i][j].y, cx = node[i][j].x;

			for (int k = 0; k < 4; k++) {
				find(cy, cx, k, map[cy][cx], 0);
			}
		}
	}


	pq.push({ 1, 0 });

	for (int i = 0; i < inum; i++) {
		int now = -1, mincost = 1e9;

		while (!pq.empty()) {
			Node temp = pq.top();
			pq.pop();
			
			now = temp.y;

			if (!chk[now]) {
				mincost = temp.x;
				break;
			}
		}

		if (mincost == 1e9)
			continue;

		ans += mincost;
		chk[now] = 1;
		for (int i = 1; i <= inum; i++) {
			if (dis[now][i] == 0)
				continue;
			pq.push({ i,dis[now][i] });
		}
	}

	bool err = false;
	for (int i = 1; i <= inum; i++) {
		if (!chk[i]) {
			err = true;
			break;
		}
	}

	if (err)
		cout << -1 << "\n";
	else
		cout << ans << "\n";

	return 0;
}