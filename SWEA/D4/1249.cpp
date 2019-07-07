#include <iostream>
#include <ios>
#include <queue>
#include <cstring>

#define MAX 101

using namespace std;

typedef pair <int, int > p;

int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int visit[MAX][MAX];


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		char map[MAX][MAX];
		queue <p > q;

		memset(visit, 0, sizeof(visit));

		cin >> N;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		visit[0][0] = 1;
		q.push({ 0,0 });

		while (!q.empty()) {
			int cx = q.front().first, cy = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cx + dir[i][0], ny = cy + dir[i][1];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				if (!visit[nx][ny]) {
					q.push({ nx,ny });
					visit[nx][ny] = visit[cx][cy] + (map[cx][cy] - '0');
				}
				else if (visit[nx][ny] > visit[cx][cy] + (map[cx][cy] - '0')) {
					q.push({ nx,ny });
					visit[nx][ny] = visit[cx][cy] + (map[cx][cy] - '0');
				}
			}
		}
		cout << "#" << t << " " << visit[N - 1][N - 1]-1 << "\n";
	}

	return 0;
}