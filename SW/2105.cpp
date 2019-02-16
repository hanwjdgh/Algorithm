#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int dir[4][2] = { {1,-1},{1,1},{-1,1},{-1,-1} };
int mp[21][21], visit[21][21];
int N, disit[101], max_v = -1;
int sx, sy;

void find(int x, int y, int cnt, int d) {
	if (d == 4)
		return;

	int nx = x + dir[d][0], ny = y + dir[d][1];

	if (nx < 0 || ny < 0 || nx >= N || ny >= N)
		return;

	if (visit[nx][ny] || disit[mp[nx][ny]]) {
		if (nx == sx && ny == sy)
			max_v = max(max_v, cnt);
		return;
	}

	visit[nx][ny] = disit[mp[nx][ny]] = 1;
	find(nx, ny, cnt + 1, d);
	find(nx, ny, cnt + 1, d + 1);
	visit[nx][ny] = disit[mp[nx][ny]] = 0;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		max_v = -1;

		cin >> N;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> mp[i][j];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = disit[mp[i][j]] = 1;
				sx = i, sy = j;
				find(i, j, 1, 0);
				visit[i][j] = disit[mp[i][j]] = 0;
			}
		}

		cout << "#" << t_case << " " << max_v << "\n";
	}

	return 0;
}
