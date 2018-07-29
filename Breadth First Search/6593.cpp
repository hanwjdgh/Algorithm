#include <iostream>
#include <ios>
#include <queue>
#include <cstring>
#include <tuple>

#define MAX 31

using namespace std;

typedef tuple <int, int, int > t;

int h[6] = { 0,0,0,0,1,-1 };
int r[6] = { 0,1,0,-1,0,0 };
int c[6] = { -1,0,1,0,0,0 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int L, R, C;
	int sx, sy, sz;
	int ex, ey, ez;
	
	while (1) {
		char bli[MAX][MAX][MAX];
		int visit[MAX][MAX][MAX] = { 0, };
		queue <t > q;
		cin >> L >> R >> C;
		if (L == 0)
			break;

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> bli[i][j][k];
					if (bli[i][j][k] == 'S') {
						sz = i, sx = j, sy = k;
					}
					else if (bli[i][j][k] == 'E') {
						ez = i, ex = j, ey = k;
					}
				}
			}
		}
		
		visit[sz][sx][sy] = 0;
		q.push({ sz,sx,sy });

		while (!q.empty()) {
			int z = get<0>(q.front()), x = get<1>(q.front()), y = get<2>(q.front());
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nh = z + h[i], nx = x + r[i], ny = y + c[i];
				if (nh < 0 || nx < 0 || ny < 0 || nh >= L || nx >= R || ny >= C)
					continue;
				if (bli[nh][nx][ny] == '#')
					continue;
				if (visit[nh][nx][ny] != 0)
					continue;
				visit[nh][nx][ny] = visit[z][x][y] + 1;
				q.push({ nh,nx,ny });
			}
		}
		int cnt = visit[ez][ex][ey];
		if (cnt > 0)
			cout << "Escaped in " << cnt << " minute(s)." << endl;
		else
			cout <<"Trapped!"<< endl;
	}
	return 0;
}