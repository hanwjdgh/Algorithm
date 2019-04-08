#include <iostream>
#include <ios>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
	int y, x, val, cnt;
};

bool operator<(Node a, Node b) {
	return (a.val > b.val);
}

Node node[2501];
int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
int N, M, K;
int cell[1002][1002];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		queue <Node > q;
		int idx = 0;
		cin >> N >> M >> K;

		for (int y = 301; y < 301 + N; y++) {
			for (int x = 301; x < 301 + M; x++) {
				cin >> cell[y][x];
				if (cell[y][x] != 0) {
					node[idx].y = y, node[idx].x = x, node[idx].val = cell[y][x], node[idx++].cnt = 0;
				}
			}
		}

		sort(node, node + idx);

		for (int i = 0; i < idx; i++)
			q.push(node[i]);

		for (int i = 0; i < K; i++) {
			int s = q.size();
			for (int j = 0; j < s; j++) {
				Node cur_node = q.front();
				q.pop();

				cur_node.cnt++;
				if (cur_node.cnt == cell[cur_node.y][cur_node.x]+1) {
					for (int k = 0; k < 4; k++) {
						Node next_node;
						next_node.y = cur_node.y + dir[k][0], next_node.x = cur_node.x + dir[k][1];
						next_node.val = cell[cur_node.y][cur_node.x], next_node.cnt = 0;
						if (cell[next_node.y][next_node.x] != 0)
							continue;
						cell[next_node.y][next_node.x] = cell[cur_node.y][cur_node.x];
						q.push(next_node);
					}
				}
				
				if (cur_node.cnt == cell[cur_node.y][cur_node.x] * 2) {
					cell[cur_node.y][cur_node.x] = -1;
					continue;
				}
				q.push(cur_node);
			}
		}

		int cnt = 0;
		for (int y = 0; y < 1002; y++) {
			for (int x = 0; x < 1002; x++) {
				if (cell[y][x] > 0) 
					cnt++;
				cell[y][x] = 0;
			}
		}

		cout << "#" << t_case << " " << cnt << "\n";
	}

	return 0;
}