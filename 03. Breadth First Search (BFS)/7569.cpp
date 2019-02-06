#include <iostream>
#include <ios>
#include <queue>
#include <tuple>
#include <algorithm>

#define MAX 101

using namespace std;

typedef tuple <int, int, int, int > t;

int box[MAX][MAX][MAX];
int visit[MAX][MAX][MAX];
int dir[6][3] = { { 1,0,0 },{ -1,0,0 },{ 0,1,0 },{ 0,-1,0 },{ 0,0,1 },{ 0,0,-1 } };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	queue <t > q;
	int M, N, H;
	int cnt = 0, max_v = 0;

	cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> box[j][k][i];
				if (box[j][k][i] == 1) {
					q.push({ j,k,i,0 });
					visit[j][k][i] = 1;
				}
				if (box[j][k][i] == 0)
					cnt++;
			}
		}
	}

	int chk = 0;
	while (!q.empty()) {
		int cx = get<0>(q.front()), cy = get<1>(q.front()), cz = get<2>(q.front()), ccnt = get<3>(q.front());
		q.pop();

		max_v = max(max_v, ccnt);

		for (int j = 0; j < 6; j++) {
			int nx = cx + dir[j][0], ny = cy + dir[j][1], nz = cz + dir[j][2];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H || visit[nx][ny][nz] || box[nx][ny][nz] == -1)
				continue;

			chk++;
			q.push({ nx,ny,nz, ccnt+1 });
			visit[nx][ny][nz] = 1;
			box[nx][ny][nz] = 1;
		}
	}

	if (cnt == chk)
		cout << max_v << "\n";
	else
		cout << "-1" << "\n";

	return 0;
}