#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

struct point {
	int y, x;
};

point pstr[4];
int N, idx, A[101][101], visit[101][101];
int dir[4][2] = { { 1,-1 },{ 1,1 },{ -1,1 },{ -1,-1 } };
int sy, sx, ans = 1e9;

void find(int cy, int cx, int d) {
	if (d == 4)
		return;

	int ny = cy + dir[d][0], nx = cx + dir[d][1];

	if (ny < 0 || nx < 0 || ny >= N || nx >= N)
		return;

	if (visit[ny][nx]) {
		if (sy == ny && sx == nx) {
			int d1 = pstr[0].y - sy, d2 = pstr[2].x - sx;
			int max_v = 0, min_v = 40000, t_val;
			int temp[101][101] = { 0, };

			for (int y = 0; y < N; y++)
				for (int x = 0; x < N; x++)
					temp[y][x] = (visit[y][x] == 1) ? -1 : A[y][x];
		
			int pnt[4][4] = { {0,sy + d1,0,sx + 1},{0,sy + d2 + 1,sx + 1,N},{sy + d1,N,0,sx - d1 + d2},{sy + d2 + 1,N,sx - d1 + d2,N} };

			for (int i = 0; i < 4; i++) {
				t_val = 0;
				if (i % 2 == 0) {
					for (int y = pnt[i][0]; y < pnt[i][1]; y++) {
						for (int x = pnt[i][2]; x < pnt[i][3]; x++) {
							if (temp[y][x] == -1)
								break;
							t_val += temp[y][x];
							temp[y][x] = 0;
						}
					}
				}

				else {
					for (int y = pnt[i][0]; y < pnt[i][1]; y++) {
						for (int x = pnt[i][3]-1; x >= pnt[i][2]; x--) {
							if (temp[y][x] == -1)
								break;
							t_val += temp[y][x];
							temp[y][x] = 0;
						}
					}
				}

				max_v = max(max_v, t_val);
				min_v = min(min_v, t_val);
			}

			t_val = 0;
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					if (temp[y][x] == 0)
						continue;

					else if (temp[y][x] == -1)
						t_val += A[y][x];

					else
						t_val += temp[y][x];
				}
			}

			max_v = max(max_v, t_val);
			min_v = min(min_v, t_val);
		
			ans = min(ans, (max_v - min_v));

		}
		return;
	}

	visit[ny][nx] = 1;
	find(ny, nx, d);
	pstr[idx].y = ny, pstr[idx++].x = nx;
	find(ny, nx, d + 1);
	idx--;
	visit[ny][nx] = 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> A[r][c];

	for (int y = 0; y < N - 2; y++) {
		for (int x = 1; x < N - 1; x++) {
			sy = y, sx = x;
			visit[y][x] = 1;
			find(y, x, 0);
			visit[y][x] = 0;
		}
	}

	cout << ans << "\n";

	return 0;
}