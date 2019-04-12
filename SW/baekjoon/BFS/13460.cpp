#include <iostream>
#include <ios>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int ry, rx, by, bx, cnt;
};

Node node;
char map[11][11];
int visit[11][11][11][11];
int N, M;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int ans = -1;

	queue <Node > q;

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'R') 
				node.ry = y, node.rx = x;
			if (map[y][x] == 'B')
				node.by = y, node.bx = x;
		}
	}

	visit[node.ry][node.rx][node.by][node.bx] = 1;
	q.push(node);

	while (!q.empty()) {
		Node cur_node = q.front();
		q.pop();

		if (cur_node.cnt > 10)
			break;
		if (map[cur_node.ry][cur_node.rx] == 'O') {
			ans = cur_node.cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			Node next_node = cur_node;

			while (1) {
				next_node.ry += dir[i][0], next_node.rx += dir[i][1];
				if (map[next_node.ry][next_node.rx] == '#') {
					next_node.ry -= dir[i][0], next_node.rx -= dir[i][1];
					break;
				}
				if (map[next_node.ry][next_node.rx] == 'O')
					break;
			}

			while (1) {
				next_node.by += dir[i][0], next_node.bx += dir[i][1];
				if (map[next_node.by][next_node.bx] == '#') {
					next_node.by -= dir[i][0], next_node.bx -= dir[i][1];
					break;
				}
				if (map[next_node.by][next_node.bx] == 'O')
					break;
			}

			if (map[next_node.by][next_node.bx] == 'O')
				continue;

			if (next_node.ry == next_node.by && next_node.rx == next_node.bx) {
				switch (i){
				case 0:
					cur_node.rx < cur_node.bx ? next_node.rx-- : next_node.bx--;
					break;
				case 1:
					cur_node.ry < cur_node.by ? next_node.ry-- : next_node.by--;
					break;
				case 2:
					cur_node.rx < cur_node.bx ? next_node.bx++ : next_node.rx++;
					break;
				case 3:
					cur_node.ry < cur_node.by ? next_node.by++ : next_node.ry++;
					break;
				default:
					break;
				}
			}

			if (!visit[next_node.ry][next_node.rx][next_node.by][next_node.bx]) {
				next_node.cnt++;
				q.push(next_node);
				visit[next_node.ry][next_node.rx][next_node.by][next_node.bx] = 1;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}