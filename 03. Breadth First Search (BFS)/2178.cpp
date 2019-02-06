#include <iostream>
#include <ios>
#include <queue>
#include <tuple>

#define MAX 101

using namespace std;

typedef tuple <int, int, int > t;

char maze[MAX][MAX];
int visit[MAX][MAX];
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	queue <t > q;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> maze[i][j];

	q.push({ 1,1,1 });
	visit[1][1] = 1;

	while (!q.empty()) {
		int cx = get<0>(q.front()), cy = get<1>(q.front()), ccnt = get<2>(q.front());
		q.pop();

		if (cx == N && cy == M) {
			cout << ccnt << "\n";
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if (nx <= 0 || ny <= 0 || nx >= N + 1 || ny >= M + 1 || visit[nx][ny] || maze[nx][ny] == '0')
				continue;
			q.push({ nx,ny,ccnt + 1 });
			visit[nx][ny] = 1;
		}
	}

	return 0;
}