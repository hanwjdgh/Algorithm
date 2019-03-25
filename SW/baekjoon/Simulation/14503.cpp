#include <iostream>
#include <ios>

using namespace std;

int board[51][51];
int N, M, r, c, di, cnt;
int dir[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> r >> c >> di;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> board[y][x];

	bool find = true;
	while (find) {
		find = false;

		if (!board[r][c]) {
			cnt++;
			board[r][c] = 2;
		}

		for (int i = 0; i < 4; i++) {
			di = (di + 3) % 4;
			int ny = r + dir[di][0], nx = c + dir[di][1];
			if (!board[ny][nx]) {
				r = ny, c = nx;
				find = true;
				break;
			}
		}

		if (!find) {
			di = (di + 2) % 4;
			int ny = r + dir[di][0], nx = c + dir[di][1];
			di = (di + 2) % 4;
			if (board[ny][nx] != 1) {
				r = ny, c = nx;
				find = true;
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}