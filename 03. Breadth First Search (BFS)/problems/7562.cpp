#include <iostream>
#include <ios>
#include <queue>
#include <cstring>
#include <tuple>

#define MAX 301

using namespace std;

typedef tuple <int, int, int > t;

int visit[MAX][MAX];
int dir[8][2] = { {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T, I;

	cin >> T;

	while (T--) {
		int sx, sy, fx, fy;
		int chk = 0;
		queue <t > q;

		memset(visit, 0, sizeof(visit));

		cin >> I;
		cin >> sx >> sy >> fx >> fy;

		q.push({ sx,sy,0 });
		visit[sx][sy] = 1;

		while (!q.empty()) {
			int cx = get<0>(q.front()), cy = get<1>(q.front()), ccnt = get<2>(q.front());
			q.pop();

			if (cx == fx && cy == fy) {
				cout << ccnt << "\n";
				chk = 1;
				break;
			}

			for (int i = 0; i < 8; i++) {
				int nx = cx + dir[i][0], ny = cy + dir[i][1];

				if (nx < 0 || ny < 0 || nx >= I || ny >= I || visit[nx][ny])
					continue;
				q.push({ nx,ny,ccnt + 1 });
				visit[nx][ny] = 1;
			}
		}
		
		if (!chk)
			cout << "0" << "\n";
	}

	return 0;
}