#include <iostream>
#include <ios>
#include <queue>
#include <algorithm>

#define MAX 301

using namespace std;

typedef pair <int, int > p;

int dx[8] = { -1,-2,-2,-1,1,2,2,1 }, dy[8] = { -2,-1,1,2,2,1,-1,-2 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;
	while (T--) {
		int chess[MAX][MAX] = { 0, }, visit[MAX][MAX] = { 0, };
		int I;
		int sx, sy, fx, fy;
		queue <p > q;
		cin >> I >> sx >> sy >> fx >> fy;

		q.push({ sx,sy });
		visit[sx][sy] = 1;
		while (!q.empty()) {
			int cx = q.front().first, cy = q.front().second;
			q.pop();
			if (cx == fx&&cy == fy) {
				cout << visit[cx][cy]-1 << endl;
				break;
			}
			for (int i = 0; i < 8; i++) {
				int nx = cx + dx[i], ny = cy + dy[i];
				if (nx < 0 || ny < 0 || nx >= I || ny >= I)
					continue;
				if (visit[nx][ny] != 0)
					continue;
				visit[nx][ny] = visit[cx][cy] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return 0;
}