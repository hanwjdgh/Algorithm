#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
int map[101][101];
int N, M, K, cnt;
vector <int > v;

void dfs(int x, int y) {
	map[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 0 && tx < M && ty >= 0 && ty < N && !map[tx][ty]) {
			cnt++;
			dfs(tx, ty);
		}
	}
}

int main() {
	int a, b, c, d;

	memset(map, 0, sizeof(map));
	scanf("%d %d %d", &M, &N, &K);
	while (K--) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int i = M - d; i < M - b; i++) {
			for (int j = a; j < c; j++)
				map[i][j] = 1;
		}
	}
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!map[i][j]) {
				cnt = 1;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}

	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);	
	return 0;
}