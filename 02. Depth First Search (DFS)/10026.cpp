#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
char map[101][101];
int visit[101][101];
int N;
vector <int > v;

void dfs(int x, int y, char cur) {
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 0 && tx < N && ty >= 0 && ty < N && !visit[tx][ty] && cur == map[tx][ty])
			dfs(tx, ty, cur);
	}
}

int main() {
	int T = 2;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		cin >> map[i];

	while (T--) {
		memset(visit, 0, sizeof(visit));
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) {
					cnt++;
					dfs(i, j, map[i][j]);
				}
			}
		}
		v.push_back(cnt);
		if (T == 1) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j] == 'G')
						map[i][j] = 'R';
				}
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	return 0;
}