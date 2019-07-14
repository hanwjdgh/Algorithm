#include <iostream>
#include <ios>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
	int y, x;
};

int T, N, ans;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int board[101][101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int max_v = 0;
		ans = 0;
		
		cin >> N;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> board[y][x];
				max_v = max(max_v, board[y][x]);
			}
		}

		for (int i = 0; i <= max_v; i++) {
			int cnt = 0;
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					if (board[y][x] == i)
						board[y][x] = 0;
				}
			}

			int visit[101][101] = { 0, };

			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					if (!board[y][x] || visit[y][x])
						continue;

					cnt++;
					queue <Node >q;
					q.push({ y,x });
					visit[y][x] = 1;

					while (!q.empty()) {
						int cy = q.front().y, cx = q.front().x;
						q.pop();

						for (int j = 0; j < 4; j++) {
							int ny = cy + dir[j][0], nx = cx + dir[j][1];
							if (ny < 0 || nx < 0 || ny >= N || nx >= N || visit[ny][nx] || board[ny][nx] == 0)
								continue;
							visit[ny][nx] = 1;
							q.push({ ny,nx });
						}
					}
				}
			}
			
			ans = max(ans, cnt);
		}

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}