#include <iostream>
#include <ios>
#include <queue>

using namespace std;

struct Node {
	int y, x, d, cnt;
};

struct Holl {
	int y, x;
};

Node next_node;
int block[6][4] = { { 0,0,0,0 },{ 1,3,0,2 },{ 3,2,0,1 },{ 2,0,3,1 },{ 2,3,1,0 },{ 2,3,0,1 } };
int dir[4][2] = { { 0,-1 },{ -1,0 },{ 0,1 },{ 1,0 } };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		Holl holl[6][2];
		int N, max_v = 0, board[101][101] = { 0, };
		int idx[6] = { 0, };
		cin >> N;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> board[y][x];
				if (board[y][x] >= 6) {
					int temp = board[y][x] - 6;
					holl[temp][idx[temp]].y = y, holl[temp][idx[temp]].x = x;
					idx[temp]++;
				}
			}
		}

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (board[y][x] != 0)
					continue;
				board[y][x] = -2;
				for (int i = 0; i < 4; i++) {
					Node node;
					node.y = y, node.x = x, node.d = i, node.cnt = 0;
					queue <Node >q;
					q.push(node);

					while (!q.empty()) {
						Node cur_node = q.front();
						next_node.y = cur_node.y + dir[cur_node.d][0], next_node.x = cur_node.x + dir[cur_node.d][1];
						next_node.d = cur_node.d, next_node.cnt = cur_node.cnt;

						int temp = board[next_node.y][next_node.x];
						q.pop();

						if (next_node.y < 0 || next_node.x < 0 || next_node.y >= N || next_node.x >= N) {
							next_node.d = ((cur_node.d + 2) % 4), next_node.cnt++;
							q.push(next_node);
							continue;
						}
						if (temp == -1 || temp == -2) {
							max_v = max(max_v, cur_node.cnt);
							continue;
						}

						if (temp == 0) {
							next_node.d = cur_node.d, next_node.cnt = cur_node.cnt;
							q.push(next_node);
						}
						else if (temp >= 1 && temp <= 5) {
							next_node.d = block[temp][cur_node.d], next_node.cnt++;
							q.push(next_node);
						}
						else {
							if (holl[temp - 6][0].y == next_node.y && holl[temp - 6][0].x == next_node.x) 
								next_node.y = holl[temp - 6][1].y, next_node.x = holl[temp - 6][1].x;
							else 
								next_node.y = holl[temp - 6][0].y, next_node.x = holl[temp - 6][0].x;
							q.push(next_node);
						}
					}
				}
				board[y][x] = 0;
			}
		}

		cout << "#" << t << " " << max_v << "\n";
	}

	return 0;
}