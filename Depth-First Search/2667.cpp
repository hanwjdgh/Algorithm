#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
char map[26][26];
int N, cnt;
vector <int > v;

void dfs(int x, int y) {
	map[x][y] = '0';
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 0 && tx < N && ty >= 0 && ty < N && map[tx][ty]=='1') {
			cnt++;
			dfs(tx, ty);	
		}
	}
}

int main() {
	int max_val = 0;
	int a, b;

	memset(map, 0, sizeof(map));
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		cin >> map[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j]=='1') {
				cnt = 1;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%d\n", v[i]);
	return 0;
}