#include <iostream>
#include <ios>
#include <cstring>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

typedef pair <int, int > p;
typedef tuple <int, int, int> t;

int w, h;
int dir[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
int idx[21][21], visit[21][21];
int ad[12][12];
char map[21][21];

void bfs(int id, int x, int y) {
	queue <t > q;

	q.push({ x,y,0 });
	visit[x][y] = 1;

	while (!q.empty()) {
		int cx = get<0>(q.front()), cy = get<1>(q.front()), cw = get<2>(q.front());
		q.pop();

		if (idx[cx][cy] != 0) {
			ad[id][idx[cx][cy]] = cw;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w || visit[nx][ny] || map[nx][ny] == 'x')
				continue;
			visit[nx][ny] = 1;
			q.push({ nx,ny,cw + 1 });
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		int cnt = 2, ans = 1e9;
		int sx, sy;
		bool error = false;
		memset(visit, 0, sizeof(visit));
		memset(idx, 0, sizeof(idx));
		memset(ad, 0, sizeof(ad));

		cin >> w >> h;
		if (w == 0 || h == 0)
			break;

		vector <p > v;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'o') {
					sx = i, sy = j;
					idx[i][j] = 1;
				}
				if (map[i][j] == '*') {
					v.push_back({ i,j });
					idx[i][j] = cnt++;
				}
			}
		}
		if (cnt == 2) {
			cout << "0" << endl;
			continue;
		}

		bfs(idx[sx][sy], sx, sy);
		for (int i = 0; i < v.size(); i++) {
			memset(visit, 0, sizeof(visit));
			int x = v[i].first, y = v[i].second;
			bfs(idx[x][y], x, y);
		}

		do {
			int temp = ad[1][idx[v[0].first][v[0].second]];
			if (temp == 0)
				error = true;
			for (int i = 0; i < v.size() - 1; i++) {
				if (ad[idx[v[i].first][v[i].second]][idx[v[i + 1].first][v[i + 1].second]] == 0)
					error = true;
				temp += ad[idx[v[i].first][v[i].second]][idx[v[i + 1].first][v[i + 1].second]];
			}
			ans = min(ans, temp);
		} while (next_permutation(v.begin(), v.end()));
		if (error)
			cout << "-1" << "\n";
		else
			cout << ans << "\n";
	}
	return 0;
}