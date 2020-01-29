#include <iostream>
#include <ios>
#include <queue>

using namespace std;

struct Node {
	int cy, cx, day, cnt;
};

int n, m, maze[501][501], ans_cnt = -1;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
bool visited[501][501][2][11];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	queue <Node > q;

	cin >> n >> m;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			cin >> maze[y][x];

	q.push({ 0, 0, 0, 0 });
	visited[0][0][0][0] = true;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		if (cur.cy == n - 1 && cur.cx == n - 1) {
			ans_cnt = cur.cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = cur.cy + dir[i][0], nx = cur.cx + dir[i][1];
			int nday = (((cur.cnt + 1) / m) % 2 == 1) ? 1 : 0;
			int ncnt = (cur.cnt + 1) % m;

			if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx][nday][ncnt])
				continue;

			if (maze[ny][nx] == 1) {
				if (cur.day == 0)
					continue;

				while (1) {
					ny += dir[i][0], nx += dir[i][1];

					if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx][nday][ncnt])
						break;

					if (maze[ny][nx] == 0) {

						visited[ny][nx][nday][ncnt] = true;
						q.push({ ny, nx, nday, cur.cnt + 1 });
						break;
					}
				}
			}
			else {
				visited[ny][nx][nday][ncnt] = true;
				q.push({ ny, nx, nday, cur.cnt + 1 });
			}
		}
	}

	if (ans_cnt == -1)
		cout << -1;
	else
		cout << ans_cnt / (2 * m) + 1 << " " << (((ans_cnt / m) % 2 == 1) ? "moon" : "sun");

	return 0;
}