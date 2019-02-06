#include <iostream>
#include <ios>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX 51

using namespace std;

typedef pair <int, int > p;

int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
char imap[MAX][MAX];
int visit[MAX][MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int R, C, max_v = 0;

	cin >> R >> C;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> imap[i][j];

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (imap[i][j] == 'L') {
				memset(visit, 0, sizeof(visit));
				queue <p > q;

				q.push({ i,j });
				visit[i][j] = 1;

				while (!q.empty()) {
					int cx = q.front().first, cy = q.front().second;
					q.pop();

					max_v = max(max_v, visit[cx][cy]);

					for (int k = 0; k < 4; k++) {
						int nx = cx + dir[k][0], ny = cy + dir[k][1];

						if (nx < 0 || ny < 0 || nx >= R || ny >= C || visit[nx][ny] || imap[nx][ny] == 'W')
							continue;
						q.push({ nx,ny });
						visit[nx][ny] = visit[cx][cy] + 1;
					}
				}
			}
		}
	}

	cout << max_v - 1 << "\n";

	return 0;
}