#include <iostream>
#include <ios>

using namespace std;

struct Point {
	int y, x;
};

Point point[2];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int fconv[4] = { 3,0,1,2 }, sconv[4] = { 1,2,3,0 };
int map[51][51];
int R, C, T, sum, p_cnt;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C >> T;

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> map[y][x];
			if (map[y][x] == -1) {
				point[p_cnt].y = y, point[p_cnt].x = x;
				p_cnt++;
			}
		}
	}


	while (T--) {
		int temp[51][51] = { 0, };

		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				if (map[y][x] == 0)
					continue;

				int cnt = 0;
				for (int i = 0; i < 4; i++) {
					int ny = y + dir[i][0], nx = x + dir[i][1];
					if (ny < 0 || nx < 0 || ny >= R || nx >= C || map[ny][nx] == -1)
						continue;
					cnt++;
					temp[ny][nx] += map[y][x] / 5;
				}
				temp[y][x] += (map[y][x] - (map[y][x] / 5)*cnt);
			}
		}

		int ny = point[0].y, nx = point[0].x, d = 0, t = 0;
		while (1) {
			ny += dir[d][0], nx += dir[d][1];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C) {
				ny -= dir[d][0], nx -= dir[d][1];
				d = fconv[d];
				continue;
			}

			if (ny == point[0].y && nx == point[0].x)
				break;

			int tmp = temp[ny][nx];
			temp[ny][nx] = t;
			t = tmp;
		}

		ny = point[1].y, nx = point[1].x, d = 0, t = 0;
		while (1) {
			ny += dir[d][0], nx += dir[d][1];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C) {
				ny -= dir[d][0], nx -= dir[d][1];
				d = sconv[d];
				continue;
			}

			if (ny == point[1].y && nx == point[1].x)
				break;

			int tmp = temp[ny][nx];
			temp[ny][nx] = t;
			t = tmp;
		}

		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				if (map[y][x] == -1)
					continue;
				map[y][x] = temp[y][x];
			}
		}
	}

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (map[y][x] == -1)
				continue;
			sum += map[y][x];
		}
	}

	cout << sum << "\n";

	return 0;
}