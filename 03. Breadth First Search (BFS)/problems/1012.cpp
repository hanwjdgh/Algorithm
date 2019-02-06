#include <iostream>
#include <ios>
#include <queue>
#include <cstring>

#define MAX 51

using namespace std;

typedef pair <int, int > p;

int visit[MAX][MAX];
int area[MAX][MAX];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T, M, N, K;
	int a, b;

	cin >> T;

	while (T--) {
		memset(visit, 0, sizeof(visit));
		memset(area, 0, sizeof(area));
		int cnt = 0;
		cin >> M >> N >> K;

		while (K--) {
			cin >> a >> b;
			area[a][b] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j] && area[i][j] == 1) {
					cnt++;
					queue <p > q;
					q.push({ i,j });
					visit[i][j] = 1;

					while (!q.empty()) {
						int x = q.front().first, y = q.front().second;
						q.pop();

						for (int i = 0; i < 4; i++) {
							int nx = x + dir[i][0], ny = y + dir[i][1];
							if (nx < 0 || ny < 0 || nx >= M || ny >= N || visit[nx][ny] || area[nx][ny] == 0)
								continue;
							q.push({ nx,ny });
							visit[nx][ny] = 1;
						}
					}

				}
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}