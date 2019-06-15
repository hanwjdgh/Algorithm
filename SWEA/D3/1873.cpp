#include <iostream>
#include <ios>

using namespace std;

char cmd, map[21][21];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
char td[4] = { '^','>','v','<' };
char d[4] = { 'U', 'R', 'D', 'L' };
int T, H, W, N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int sy = 0, sx = 0, ans = 0, di = 0;

		cin >> H >> W;

		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				cin >> map[y][x];

				if (map[y][x] == '^') {
					sy = y, sx = x;
					di = 0;
					map[y][x] = '.';
				}
				else if (map[y][x] == '>') {
					sy = y, sx = x;
					di = 1;
					map[y][x] = '.';
				}
				else if (map[y][x] == 'v') {
					sy = y, sx = x;
					di = 2;
					map[y][x] = '.';
				}
				else if (map[y][x] == '<') {
					sy = y, sx = x;
					di = 3;
					map[y][x] = '.';
				}
			}
		}

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> cmd;

			if (cmd == 'S') {

				int ny = sy, nx = sx;
				while (1) {
					ny += dir[di][0], nx += dir[di][1];

					if (ny < 0 || nx < 0 || ny >= H || nx >= W || map[ny][nx] == '#')
						break;

					if (map[ny][nx] == '*') {
						map[ny][nx] = '.';
						break;
					}
				}
			}
			else {
				for (int j = 0; j < 4; j++) {
					if (cmd == d[j]) {
						di = j;
						break;
					}
				}

				sy += dir[di][0], sx += dir[di][1];

				if (sy < 0 || sx < 0 || sy >= H || sx >= W || map[sy][sx] != '.') {
					sy -= dir[di][0], sx -= dir[di][1];
				}
			}
		}

		cout << "#" << t_case << " ";

		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				if (y == sy && x == sx)
					cout << td[di];
				else
					cout << map[y][x];
			}
			cout << "\n";
		}
	}

	return 0;
}