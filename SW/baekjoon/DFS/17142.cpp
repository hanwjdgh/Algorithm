#include <iostream>
#include <ios>
#include <queue>

using namespace std;

struct Node {
	int y, x;
};

Node node[2501];
int map[51][51], visit[2501];
int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
int N, M, idx, ans = 2501;

void find(int cnt, int cur) {
	if (cnt == M) {
		int chk = 1;
		int temp[51][51] = { 0, };
		queue <Node > q;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x] == 1)
					temp[y][x] = -4;
				else
					temp[y][x] = -3;
			}
		}
		for (int i = 0; i < cnt; i++) {
			q.push({ node[visit[i]].y ,node[visit[i]].x });
			temp[node[visit[i]].y][node[visit[i]].x] = 0;
		}

		while (!q.empty()) {
			int qs = q.size();

			for (int i = 0; i < qs; i++) {
				Node cur = q.front();
				q.pop();

				int cy = cur.y, cx = cur.x;

				for (int k = 0; k < 4; k++) {
					int ny = cy + dir[k][0], nx = cx + dir[k][1];

					if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] == 1 || temp[ny][nx] != -3)
						continue;
					if (map[ny][nx] == 2)
						temp[ny][nx] = -1;
					else {
						if (temp[ny][nx] == -3)
							temp[ny][nx] = chk;
						else if (temp[ny][nx] > chk)
							temp[ny][nx] = chk;
					}
					q.push({ ny,nx });
				}
			}

			chk++;
		}

		int tmp = 0;
		bool err = false;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (temp[y][x] == -4 || temp[y][x] == -1)
					continue;
				else if (temp[y][x] == -3) {
					err = true;
					break;
				}
				else
					tmp = max(tmp, temp[y][x]);
			}
			if (err)
				break;
		}

		if (!err)
			ans = min(ans, tmp);

		return;
	}

	for (int i = cur; i < idx; i++) {
		visit[cnt] = i;
		find(cnt + 1, i + 1);
		visit[cnt] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];

			if (map[y][x] == 2) {
				node[idx].y = y;
				node[idx++].x = x;
			}
		}
	}

	find(0, 0);

	ans = (ans == 2501) ? -1 : ans;

	cout << ans << "\n";

	return 0;
}