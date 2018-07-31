#include <iostream>
#include <ios>
#include <cstring>
#include <queue>
#include <algorithm>

#define MAX 1001
#define INF 1000000000

using namespace std;

typedef pair <int, int > p;
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int visit[MAX][MAX] = { 0, };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;
	while (T--) {
		int w, h, chk = 0, min_v = INF;
		memset(visit, 0, sizeof(visit));
		char bil[MAX][MAX];

		queue <p > sq, fq;

		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> bil[i][j];
				if (bil[i][j] == '*')
					fq.push({ i,j });
				if (bil[i][j] == '@') {
					visit[i][j] = 1;
					sq.push({ i,j });
				}
			}
		}

		while (!sq.empty() || !fq.empty()) {
			int ssize = sq.size(), fsize = fq.size();

			for (int i = 0; i < fsize; i++) {
				int fx = fq.front().first, fy = fq.front().second;
				fq.pop();
				visit[fx][fy] = 1;
				for (int i = 0; i < 4; i++) {
					int nx = fx + dx[i], ny = fy + dy[i];
					if (nx >= 0 && nx < h&&ny >= 0 && ny < w && visit[nx][ny] == 0 && bil[nx][ny] != '#') {
						visit[nx][ny] = 1;
						bil[nx][ny] = '*';
						fq.push({ nx,ny });
					}
				}
			}

			for (int i = 0; i < ssize; i++) {
				int csx = sq.front().first, csy = sq.front().second;
				sq.pop();
				if (csx == 0 || csx == h - 1 || csy == 0 || csy == w - 1) {
					min_v = min(min_v, visit[csx][csy]);
				}

				for (int i = 0; i < 4; i++) {
					int nx = csx + dx[i], ny = csy + dy[i];
					if (nx >= 0 && nx < h&&ny >= 0 && ny < w && visit[nx][ny] == 0 && bil[nx][ny] == '.') {
						visit[nx][ny] = visit[csx][csy] + 1;
						bil[nx][ny] = '@';
						sq.push({ nx,ny });
					}
				}

			}

		}
		if (min_v == INF)
			cout << "IMPOSSIBLE" << "\n";
		else
			cout << min_v << "\n";
	}

	return 0;
}