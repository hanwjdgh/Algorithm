#include <iostream>
#include <ios>
#include <queue>

using namespace std;

struct Robot {
	int y, x, di;
};

Robot robot;
int board[51][51];
int dir[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
int conv[4][4] = { { 3,2,1,0 },{ 0,3,2,1 },{ 1,0,3,2 },{ 2,1,0,3 } }, bconv[4] = { 2,3,0,1 };
int N, M, cnt;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	cin >> robot.y >> robot.x >> robot.di;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> board[y][x];

	queue <Robot > q;
	q.push(robot);

	while (!q.empty()) {
		Robot cur = q.front();
		q.pop();

		int cy = cur.y, cx = cur.x, cdi = cur.di;

		if (!board[cy][cx]) {
			cnt++;
			board[cy][cx] = 2;
		}

		for (int i = 0; i < 4; i++) {
			Robot next;
			next.di = conv[cdi][i];
			next.y = cy + dir[next.di][0], next.x = cx + dir[next.di][1];

			if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= M || board[next.y][next.x] != 0)
				continue;
			q.push(next);
			break;
		}

		if (q.empty()) {
			Robot next;
			next.di = cdi;
			next.y = cy + dir[bconv[cdi]][0], next.x = cx + dir[bconv[cdi]][1];

			if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= M || board[next.y][next.x] == 1)
				break;
			q.push(next);
		}
	}

	cout << cnt << "\n";

	return 0;
}