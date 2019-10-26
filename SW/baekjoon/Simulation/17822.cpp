#include <iostream>
#include <ios>
#include <cstring>

using namespace std;

struct Cst {
	int x, d, k;
};

Cst cst[51];
int N, M, T, ans, cnt;
int dir[5][2] = { {0,0},{-1,0},{0,1},{0,-1},{1,0} };
int circle[51][51], visit[51][51];
bool chk;

void dfs(int y, int x, int val) {
	int s = 1, e = 4;

	if (y == 1)
		s = 2;

	if (y == N)
		e = 3;

	for (int i = s; i <= e; i++) {
		int ny = y + dir[i][0], nx = x + dir[i][1];

		if (nx < 1)
			nx = M;
		else if (nx > M)
			nx = 1;

		if (visit[ny][nx] || circle[ny][nx] == 0 || circle[ny][nx] != val)
			continue;

		chk = true;
		circle[ny][nx] = 0;
		visit[ny][nx] = 1;
		dfs(ny, nx, val);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> circle[i][j];

	for (int i = 0; i < T; i++)
		cin >> cst[i].x >> cst[i].d >> cst[i].k;

	for (int i = 0; i < T; i++) {
		memset(visit, 0, sizeof(visit));
		cnt = 0;
		for (int a = 1; a <= N; a++) {
			if (a%cst[i].x != 0)
				continue;

			if (cst[i].d == 0) {
				for (int b = 0; b < cst[i].k; b++) {
					int temp = circle[a][M];
					for (int j = M; j > 1; j--)
						circle[a][j] = circle[a][j - 1];
					circle[a][1] = temp;
				}
			}

			else {
				for (int b = 0; b < cst[i].k; b++) {
					int temp = circle[a][1];
					for (int j = 1; j < M; j++)
						circle[a][j] = circle[a][j + 1];
					circle[a][M] = temp;
				}
			}
		}

		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= M; x++) {
				chk = false;
				if (visit[y][x] || circle[y][x] == 0)
					continue;
				visit[y][x] = 1;
				dfs(y, x, circle[y][x]);

				if (chk) {
					circle[y][x] = 0;
					cnt++;
				}
			}
		}

		if (cnt == 0) {
			double hap = 0.0;
			int num = 0;
			for (int y = 1; y <= N; y++) {
				for (int x = 1; x <= M; x++) {
					if (circle[y][x] != 0)
						num++;

					hap += circle[y][x];
				}
			}

			hap /= num;
			for (int y = 1; y <= N; y++) {
				for (int x = 1; x <= M; x++) {
					if (circle[y][x] == 0)
						continue;

					if (circle[y][x] > hap)
						circle[y][x]--;
					else if (circle[y][x] < hap)
						circle[y][x]++;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			ans += circle[i][j];

	cout << ans << "\n";

	return 0;
}