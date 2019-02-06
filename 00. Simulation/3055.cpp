#include <iostream>
#include <ios>
#include <tuple>
#include <vector>
#include <queue>

#define MAX 51

using namespace std;

typedef tuple <int, int, int > t;
typedef pair <int, int > p;

char map[MAX][MAX];
int visit[MAX][MAX];
int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int R, C, chk = 0;
	queue <p > wq;
	queue <t > q;

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') {
				wq.push({ i,j });
				visit[i][j] = 1;
			}
			if (map[i][j] == 'S') {
				q.push({ i,j,0 });
				visit[i][j] = 1;
			}
		}
	}

	while (!wq.empty() || !q.empty()) {
		int wsize = wq.size(), msize = q.size();

		for (int i = 0; i < wsize; i++) {
			int cx = wq.front().first, cy = wq.front().second;
			wq.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cx + dir[i][0], ny = cy + dir[i][1];

				if (nx < 0 || ny < 0 || nx >= R || ny >= C || visit[nx][ny])
					continue;
				if (map[nx][ny] == '.') {
					map[nx][ny] = '*';
					wq.push({ nx,ny });
					visit[nx][ny] = 1;
				}
			}
		}

		for (int i = 0; i < msize; i++) {
			int cx = get<0>(q.front()), cy = get<1>(q.front()), cnt = get<2>(q.front());
			q.pop();

			if (map[cx][cy] == 'D') {
				cout << cnt << "\n";
				chk = 1;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int nx = cx + dir[i][0], ny = cy + dir[i][1];

				if (nx < 0 || ny < 0 || nx >= R || ny >= C || visit[nx][ny])
					continue;
				if (map[nx][ny] == '.' || map[nx][ny] == 'D') {
					q.push({ nx,ny,cnt + 1 });
					visit[nx][ny] = 1;
				}
			}
		}
		if (chk)
			break;
	}

	if (!chk)
		cout << "KAKTUS" << "\n";

	return 0;
}