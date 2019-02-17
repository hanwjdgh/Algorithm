#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int mount[9][9], visit[9][9];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int N, K, ans, chk;

void find(int x, int y, int len) {
	ans = max(ans, len);

	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0], ny = y + dir[i][1];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny])
			continue;

		if (mount[nx][ny] < mount[x][y]) {
			visit[nx][ny] = 1;
			find(nx, ny, len + 1);
			visit[nx][ny] = 0;
		}
		else {
			for (int j = 1; j <= K; j++) {
				if (!chk && mount[nx][ny] - j < mount[x][y]) {
					visit[nx][ny] = 1;
					chk = 1;
					mount[nx][ny] -= j;
					find(nx, ny, len + 1);
					chk = 0;
					mount[nx][ny] += j;
					visit[nx][ny] = 0;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int max_v = 0;
		ans = chk = 0;

		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> mount[i][j];
				max_v = max(max_v, mount[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (mount[i][j] == max_v) {
					visit[i][j] = 1;
					find(i, j, 1);
					visit[i][j] = 0;
				}
			}
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}