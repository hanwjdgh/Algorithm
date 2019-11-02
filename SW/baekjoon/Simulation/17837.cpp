#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

struct Pin {
	int y, x, d, loc;
};

Pin pin[11];
int N, K, nerr, cnt;
int dir[5][2] = { { 0,0 },{ 0,1 },{ 0,-1 },{ -1,0 },{ 1,0 } };
int rdir[5] = { 0,2,1,4,3 }, max_v, ans = 1;
int board[12][12], psize[12][12];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> board[y][x];

	for (int i = 0; i < K; i++) {
		cin >> pin[i].y >> pin[i].x >> pin[i].d;
		pin[i].y--, pin[i].x--;
		pin[i].loc = 1;
		psize[pin[i].y][pin[i].x] = 1;
	}

	while (ans < 1001) {
		bool chk[11] = { false, };

		for (int i = 0; i < K; ) {
			int cy = pin[i].y, cx = pin[i].x, cloc = pin[i].loc;

			int ny = cy + dir[pin[i].d][0], nx = cx + dir[pin[i].d][1];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N || board[ny][nx] == 2) {
				if (!chk[i]) {
					pin[i].d = rdir[pin[i].d];
					chk[i] = true;
				}
				else
					i++;
				continue;
			}

			if (board[ny][nx] == 0) {
				cnt = 0;
				for (int a = 0; a < K; a++) {
					if (pin[a].y == cy && pin[a].x == cx && pin[a].loc >= cloc) {
						pin[a].y = ny, pin[a].x = nx;
						pin[a].loc = pin[a].loc - cloc + 1 + psize[ny][nx];
						cnt++;
					}
				}
				psize[ny][nx] += cnt, psize[cy][cx] -= cnt;
			}

			else if (board[ny][nx] == 1) {
				cnt = 0;
				for (int a = 0; a < K; a++) {
					if (pin[a].y == cy && pin[a].x == cx && pin[a].loc >= cloc) {
						pin[a].y = ny, pin[a].x = nx;
						pin[a].loc = psize[cy][cx] - pin[a].loc + 1 + psize[ny][nx];
						cnt++;
					}
				}
				psize[ny][nx] += cnt, psize[cy][cx] -= cnt;
			}

			max_v = max(max_v, psize[ny][nx]);

			if (max_v >= 4) {
				nerr = 1;
				break;
			}
			i++;
		}

		if (nerr)
			break;
		ans++;
	}

	if (nerr == 1)
		cout << ans << "\n";
	else
		cout << -1 << "\n";

	return 0;
}