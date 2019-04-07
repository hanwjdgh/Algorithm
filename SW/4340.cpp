#include <iostream>

using namespace std;

int map[51][51], visit[51][51];
int dir[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
int N, ans;

void dfs(int y, int x, int d, int cnt) {
	if (y == 0 && x == 0) {
		if (ans > cnt) {
			if (map[y][x] < 3 && d == 3)
				ans = cnt;
			else if (map[y][x] >= 3 && d == 0)
				ans = cnt;
		}
		return;
	}

	if (y < 0 || x < 0 || y >= N || x >= N || !map[y][x] || visit[y][x] || cnt > ans)
		return;
	
	if (y + x + cnt > ans) 
		return;
	
	visit[y][x] = cnt+1;

	if (map[y][x] < 3) {
		dfs(y + dir[d][0], x + dir[d][1], d, cnt + 1);
		visit[y][x] = 0;
	}
	else {
		if (d % 2 == 0) {
			if (map[y][x - 1] > 0 && map[y][x + 1] > 0) {
				dfs(y, x - 1, 3, cnt + 1);
				dfs(y, x + 1, 1, cnt + 1);
				visit[y][x] = 0;
			}
			else if (map[y][x - 1] > 0) {
				dfs(y, x - 1, 3, cnt + 1);
				visit[y][x] = 0;
			}
			else if (map[y][x + 1] > 0) {
				dfs(y, x + 1, 1, cnt + 1);
				visit[y][x] = 0;
			}
		}
		else {
			if (map[y - 1][x] > 0 && map[y + 1][x] > 0) {
				dfs(y - 1, x, 0, cnt + 1);
				dfs(y + 1, x, 2, cnt + 1);
				visit[y][x] = 0;
			}
			else if (map[y - 1][x] > 0) {
				dfs(y - 1, x, 0, cnt + 1);
				visit[y][x] = 0;
			}
			else if (map[y + 1][x] > 0) {
				dfs(y + 1, x, 2, cnt + 1);
				visit[y][x] = 0;
			}
		}
	}
}

int main() {
	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 1e9;

		cin >> N;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				visit[y][x] = 0;
				cin >> map[y][x];
			}
		}
	
		dfs(N - 1, N - 1, 3, 1);

		cout << "#" << t_case << " " << ans << "\n";
	}
}