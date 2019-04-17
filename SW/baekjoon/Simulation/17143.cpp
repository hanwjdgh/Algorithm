#include <iostream>
#include <ios>

using namespace std;

struct Fish {
	int fn, y, x, s, d, ls;
};

Fish fish[10001];
int dir[5][2] = { {0,0},{-1,0},{1,0},{0,1},{0,-1} };
int map[101][101];
int rconv[5] = {0,2,1,4,3};
int R, C, M, sum;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C >> M;

	for (int i = 1; i <= M; i++) {
		cin >> fish[i].y >> fish[i].x >> fish[i].s >> fish[i].d >> fish[i].fn;
		fish[i].ls = 1;
		fish[i].y--, fish[i].x--;
		map[fish[i].y][fish[i].x] = i;
	}

	for (int x = 0; x < C; x++) {
		int temp[101][101] = { 0, };

		for (int y = 0; y < R; y++) {
			if (map[y][x] == 0)
				continue;
			sum += fish[map[y][x]].fn;
			fish[map[y][x]].ls = 0;
			map[y][x] = 0;
			break;
		}

		for (int i = 1; i <= M; i++) {
			if (fish[i].ls == 0)
				continue;

			for (int j = 0; j < fish[i].s; ) {
				fish[i].y += dir[fish[i].d][0], fish[i].x += dir[fish[i].d][1];

				if (fish[i].y < 0 || fish[i].x < 0 || fish[i].y >= R || fish[i].x >= C) {
					fish[i].y -= dir[fish[i].d][0], fish[i].x -= dir[fish[i].d][1];
					fish[i].d = rconv[fish[i].d];
					continue;
				}
				j++;
			}

			if (temp[fish[i].y][fish[i].x] == 0) {
				temp[fish[i].y][fish[i].x] = i;
			}
			else {
				if (fish[temp[fish[i].y][fish[i].x]].fn < fish[i].fn) {
					fish[temp[fish[i].y][fish[i].x]].ls = 0;
					temp[fish[i].y][fish[i].x] = i;
				}
				else
					fish[i].ls = 0;
			}
		}
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				map[r][c] = temp[r][c];
	}

	cout << sum << "\n";

	return 0;
}