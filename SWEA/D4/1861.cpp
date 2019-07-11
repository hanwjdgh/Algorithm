#include <iostream>
#include <ios>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct Node {
	int y, x, cnt;
};

int map[1001][1001], visit[1001][1001];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int T, N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int ans = 0, idx = 1e9;

		memset(visit, 0, sizeof(visit));

		cin >> N;

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> map[y][x];

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {

				queue <Node > q;

				q.push({ y,x,1 });
				visit[y][x] = 1;

				while (!q.empty()) {
					int cy = q.front().y, cx = q.front().x, ccnt = q.front().cnt;
					q.pop();

					if (ans < ccnt) {
						idx = map[y][x];
						ans = ccnt;
					}

					if (ans == ccnt)
						idx = min(idx, map[y][x]);

					for (int j = 0; j < 4; j++) {
						int ny = cy + dir[j][0], nx = cx + dir[j][1];

						if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[cy][cx] + 1 != map[ny][nx] || visit[ny][nx] > visit[cy][cx] + 1)
							continue;
						q.push({ ny,nx,ccnt + 1 });
						visit[ny][nx] = visit[cy][cx] + 1;
					}
				}

			}
		}


		cout << "#" << t_case << " " << idx << " " << ans << "\n";
	}

	return 0;
}