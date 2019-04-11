#include <iostream>
#include <ios>

using namespace std;

int paper[11][11], visit[11][11];
int cp[6], ans=1e9;

bool check(int cy, int cx, int r) {
	for (int y = 0; y < r; y++) {
		int ny = cy + y;
		for (int x = 0; x < r; x++) {
			int nx = cx + x;
			if (ny > 9 || nx > 9)
				return false;
			if (!paper[ny][nx] || visit[ny][nx])
				return false;
		}
	}

	return true;
}

void dfs(int cy, int cx, int cnt) {
	if (cy == 10)
		cy = 0, cx += 1;

	if (cnt > ans)
		return;

	if (cx == 10) {
		if (ans > cnt)
			ans = cnt;
		return;
	}

	if (paper[cy][cx] == 0 || visit[cy][cx]) 
		dfs(cy + 1, cx, cnt);
	
	for (int i = 5; i >= 1; i--) {
		if (check(cy, cx, i)) {
			if (!cp[i])
				continue;
			cp[i]--;
			for (int y = 0; y < i; y++)
				for (int x = 0; x < i; x++)
					visit[cy + y][cx + x] = 1;
			dfs(cy + 1, cx, cnt + 1);
			for (int y = 0; y < i; y++)
				for (int x = 0; x < i; x++)
					visit[cy + y][cx + x] = 0;
			cp[i]++;
		}
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	for (int i = 0; i < 6; i++)
		cp[i] = 5;

	for (int y = 0; y < 10; y++)
		for (int x = 0; x < 10; x++)
			cin >> paper[y][x];

	dfs(0, 0, 0);

	if (ans == 1e9)
		ans = -1;

	cout << ans << "\n";

	return 0;
}