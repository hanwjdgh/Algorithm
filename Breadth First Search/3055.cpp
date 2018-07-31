#include <iostream>
#include <ios>
#include <cstring>
#include <queue>
#include <algorithm>

#define MAX 51
#define INF 1000000000

using namespace std;

typedef pair <int, int > p;
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int visit[MAX][MAX] = { 0, };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	int R, C, chk = 0, min_v = INF;
	memset(visit, 0, sizeof(visit));
	char sup[MAX][MAX];
	int fx, fy;

	queue <p > sq, fq;

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> sup[i][j];
			if (sup[i][j] == '*')
				fq.push({ i,j });
			if (sup[i][j] == 'S') {
				visit[i][j] = 1;
				sq.push({ i,j });
			}
			if (sup[i][j] == 'D') {
				fx = i, fy = j;
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
				if (nx >= 0 && nx < R && ny >= 0 && ny < C && visit[nx][ny] == 0 && (sup[nx][ny] == '.'|| sup[nx][ny]=='S')) {
					visit[nx][ny] = 1;
					sup[nx][ny] = '*';
					fq.push({ nx,ny });
				}
			}
		}

		for (int i = 0; i < ssize; i++) {
			int csx = sq.front().first, csy = sq.front().second;
			sq.pop();
			if (csx == fx && csy == fy) {
				min_v = min(min_v, visit[csx][csy]);
			}

			for (int i = 0; i < 4; i++) {
				int nx = csx + dx[i], ny = csy + dy[i];
				if (nx >= 0 && nx < R &&ny >= 0 && ny < C && visit[nx][ny] == 0 && (sup[nx][ny] == '.'|| sup[nx][ny] == 'D')) {
					visit[nx][ny] = visit[csx][csy] + 1;
					sq.push({ nx,ny });
				}
			}

		}

	}
	if (min_v == INF)
		cout << "KAKTUS" << "\n";
	else
		cout << min_v - 1 << "\n";
	return 0;
}