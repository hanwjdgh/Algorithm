#include <iostream>
#include <ios>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

typedef pair <int, int > p;

int map[MAX][MAX];
int visit[MAX][MAX];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int M, N, K;
	int x, y, a, b;
	vector <int > v;

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		cin >> x >> y >> a >> b;

		for (int j = M - b; j < M - y; j++)
			for (int k = x; k < a; k++)
				map[j][k] = 1;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0 || visit[i][j])
				continue;
			int cnt = 1;
			queue <p > q;

			q.push({ i,j });
			visit[i][j] = 1;

			while (!q.empty()) {
				int cx = q.front().first, cy = q.front().second;
				q.pop();

				for (int k = 0; k < 4; k++) {
					int nx = cx + dir[k][0], ny = cy + dir[k][1];
					if (nx < 0 || ny < 0 || nx >= M || ny >= N || visit[nx][ny] || map[nx][ny] != 0)
						continue;
					q.push({ nx,ny });
					visit[nx][ny] = 1;
					cnt++;
				}
			}
			v.push_back(cnt);
		}
	}
	sort(v.begin(), v.end());

	cout << v.size() << "\n";
	for (auto n : v)
		cout << n << " ";
	cout << "\n";

	return 0;
}