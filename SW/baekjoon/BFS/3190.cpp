#include <iostream>
#include <ios>
#include <queue>

using namespace std;

struct Move {
	int time;
	char bang;
};

struct Snake {
	int y, x, t;
};

Snake node;
Snake snake[10001];
Move mve[101];

int dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
int board[101][101];
int N, K, L, di, cnt;
int chk;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;

	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		board[a - 1][b - 1] = 1;
	}

	cin >> L;

	for (int i = 0; i < L; i++)
		cin >> mve[i].time >> mve[i].bang;

	queue <Snake > q;
	q.push(node);
	board[0][0] = -1;

	while (!q.empty()) {
		Snake cur = q.front();
		int cy = cur.y, cx = cur.x, time = cur.t;
		q.pop();

		if (mve[chk].time == time) {
			if (mve[chk].bang == 'L')
				di = (di + 3) % 4;
			else
				di = (di + 1) % 4;

			chk++;
		}
		cur.y = cy + dir[di][0], cur.x = cx + dir[di][1];
		cur.t += 1;

		if (cur.y < 0 || cur.y >= N || cur.x < 0 || cur.x >= N || board[cur.y][cur.x] == -1) {
			cout << cur.t << "\n";
			break;
		}

		if (board[cur.y][cur.x] == 1) 
			cnt++;
		else 
			board[snake[cnt].y][snake[cnt].x] = 0;

		for (int i = cnt; i > 0; i--)
			snake[i] = snake[i - 1];
		snake[0] = cur;
		board[cur.y][cur.x] = -1;

		q.push(cur);
	}

	return 0;
}