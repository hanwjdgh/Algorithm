#include <iostream>
#include <ios>
#include <queue>
#include <tuple>
#include <algorithm>

#define MAX 1001

using namespace std;

typedef tuple <int, int, int > t;

int box[MAX][MAX];
int visit[MAX][MAX];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int cnt = 0, chk = 0, max_v = 0;
	queue <t > q;

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 0)
				cnt++;
			if (box[i][j] == 1) {
				q.push({ i,j,0 });
				visit[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		int cx = get<0>(q.front()), cy = get<1>(q.front()), ccnt = get<2>(q.front());
		q.pop();
		max_v = max(max_v, ccnt);

		for (int i = 0; i < 4; i++) {
			int nx = cx + dir[i][0], ny = cy + dir[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny] || box[nx][ny] != 0)
				continue;
			q.push({ nx,ny, ccnt + 1 });
			visit[nx][ny] = 1;
			box[nx][ny] = 1;
			chk++;
		}
	}
	if (cnt == chk || cnt == 0)
		cout << max_v << "\n";
	else
		cout << "-1" << "\n";

	return 0;
}