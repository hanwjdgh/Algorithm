#include <iostream>
#include <ios>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX 301

using namespace std;

typedef pair <int, int > p;

int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
int visit[MAX][MAX], temp[MAX][MAX];
int ice[MAX][MAX];
int N, M;

void bfs(int a, int b) {
	queue <p > q;

	q.push({ a,b });
	visit[a][b] = 1;

	while (!q.empty()) {
		int cx = q.front().first, cy = q.front().second;
		q.pop();

		for (int j = 0; j < 4; j++) {
			int nx = cx + dir[j][0], ny = cy + dir[j][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny] || ice[nx][ny] == 0)
				continue;
			q.push({ nx,ny });
			visit[nx][ny] = 1;
		}
	}
}

int melt(int x, int y) {
	int num = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (ice[nx][ny] == 0)
			num++;
	}
	return num;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int ans = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> ice[i][j];

	while (1) {
		int cnt = 0;
		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ice[i][j] != 0 && !visit[i][j]) {
					cnt++;
					bfs(i, j);
				}
			}
		}
		if (cnt >= 2) {
			cout << ans << "\n";
			break;
		}
		if (cnt == 0) {
			cout << "0" << "\n";
			break;
		}
		ans++;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ice[i][j] == 0)
					continue;
				temp[i][j] = ice[i][j] - melt(i, j);
				if (temp[i][j] < 0)
					temp[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) 
			for (int j = 0; j < M; j++) 
				ice[i][j] = temp[i][j];

	}

	return 0;
}