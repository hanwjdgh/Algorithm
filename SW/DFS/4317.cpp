#include <iostream>

using namespace std;

int wafer[11][26], dp[26][1 << 11];
int H, W, ans;

bool check(int cy, int cx) {
	for (int y = 0; y < 2; y++) {
		int ny = cy + y;
		for (int x = 0; x < 2; x++) {
			int nx = cx + x;

			if (ny > H - 1 || nx > W - 1)
				return false;
			if (wafer[ny][nx] != 0)
				return false;
		}
	}
	return true;
}

void dfs(int cy, int cx, int cnt) {
	if (cx == W) {
		if (ans < cnt)
			ans = cnt;
		return;
	}

	if (cy == 0) {
		int bit = 0;
		for (int i = 0; i < H; i++)
			bit |= (wafer[i][cx] << i);
		if (dp[cx][bit] >= cnt)
			return;
		dp[cx][bit] = cnt;
	}
    
	int ny = cy + 1;
	int nx = cx;
	if (ny == H) {
		ny = 0;
		nx += 1;
	}

	if (check(cy, cx)) {
		for (int y = cy; y < cy + 2; y++)
			for (int x = cx; x < cx + 2; x++)
				wafer[y][x] = 1;
		dfs(ny, nx, cnt + 1);
		for (int y = cy; y < cy + 2; y++)
			for (int x = cx; x < cx + 2; x++)
				wafer[y][x] = 0;
	}
	dfs(ny, nx, cnt);
}

int main() {
	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		cin >> H >> W;
		ans = 0;

		for (int i = 0; i < 26; i++)
			for (int j = 0; j < (1 << 11); j++)
				dp[i][j] = -1;

		for (int y = 0; y < H; y++)
			for (int x = 0; x < W; x++)
				cin >> wafer[y][x];

		dfs(0, 0, 0);

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}