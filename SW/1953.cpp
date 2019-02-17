#include <iostream>
#include <ios>
#include <cstring>
#include <queue>

using namespace std;

typedef pair <int, int > p;

int mp[51][51][4], visit[51][51];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int pipe[8][4] = { {0,0,0,0},{1,1,1,1},{1,0,1,0},{0,1,0,1},{0,1,1,0},{1,1,0,0},{1,0,0,1},{0,0,1,1} };
int N, M, R, C, L;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		memset(visit, 0, sizeof(visit));
		memset(mp, 0, sizeof(mp));
		queue <p > q;
		int num, ans = 0;

		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> num;

				for (int k = 0; k < 4; k++)
					mp[i][j][k] = pipe[num][k];
			}
		}

		q.push({ R,C });
		visit[R][C] = 1;
		ans = 1;

		L -= 1;
		while (L--) {
			int s = q.size();

			for (int i = 0; i < s; i++) {
				int cx = q.front().first, cy = q.front().second;
				q.pop();

				for (int j = 0; j < 4; j++) {
					if (mp[cx][cy][j] == 0)
						continue;

					int nx = cx + dir[j][0], ny = cy + dir[j][1];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny])
						continue;

					int td = (j + 2) % 4;

					if (mp[nx][ny][td]) {
						ans++;
						q.push({ nx,ny });
						visit[nx][ny] = 1;
					}
				}
			}
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}