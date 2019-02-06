#include <iostream>
#include <ios>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX 101

using namespace std;

typedef pair <int, int > p;

int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int area[MAX][MAX];
int visit[MAX][MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int max_v = 0, max_h = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> area[i][j];
			max_h = max(area[i][j], max_h);
		}
	}

	for (int t = 0; t < max_h; t++) {
		int cnt = 0;
		memset(visit, 0, sizeof(visit));

		if (t > 0) {
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					area[i][j] -= 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j] && area[i][j] > 0) {
					cnt++;
					queue <p > q;

					q.push({ i,j });
					visit[i][j] = 1;

					while (!q.empty()) {
						int cx = q.front().first, cy = q.front().second;
						q.pop();

						for (int k = 0; k < 4; k++) {
							int nx = cx + dir[k][0], ny = cy + dir[k][1];

							if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny] || area[nx][ny] <= 0)
								continue;
							q.push({ nx,ny });
							visit[nx][ny] = 1;
						}
					}
				}
			}
		}
		max_v = max(max_v, cnt);
	}

	cout << max_v << "\n";

	return 0;
}