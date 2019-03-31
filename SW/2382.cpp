#include <iostream>
#include <ios>
#include <cstring>
#include <queue>

using namespace std;

struct Node {
	int y, x, val;
};

Node node[10001];

int cell[101][101][1001];
int d[101][101][1001], visit[101][101];
int dir[5][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
int N, M, K;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		memset(cell, 0, sizeof(cell));
		memset(d, 0, sizeof(d));
		memset(visit, 0, sizeof(visit));

		queue <Node > q;
		int ans = 0;

		cin >> N >> M >> K;

		for (int i = 0; i < K; i++) {
			int num;
			cin >> node[i].y >> node[i].x >> node[i].val >> num;
			cell[node[i].y][node[i].x][0] = node[i].val;
			d[node[i].y][node[i].x][0] = num - 1;
			q.push(node[i]);
		}

		for (int i = 1; i <= M + 1; i++) {
			memset(visit, 0, sizeof(visit));
			int qs = q.size();
			for (int j = 0; j < qs; j++) {
				Node cur_node = q.front();
				int cd = d[cur_node.y][cur_node.x][i - 1];
				q.pop();

				if (i == M + 1) {
					ans += cell[cur_node.y][cur_node.x][M];
					continue;
				}
				Node next_node = cur_node;
				next_node.y += dir[cd][0], next_node.x += dir[cd][1];
				next_node.val = cell[cur_node.y][cur_node.x][i - 1];

				if (next_node.y == 0 || next_node.x == 0 || next_node.y == N - 1 || next_node.x == N - 1) 
					cd = (5 - cd) % 4, next_node.val /= 2;

				d[cur_node.y][cur_node.x][i - 1] = 0;
				if (visit[next_node.y][next_node.x] == 0) {
					d[next_node.y][next_node.x][i] = cd;
					visit[next_node.y][next_node.x] = next_node.val;
					q.push(next_node);
				}
				else if (visit[next_node.y][next_node.x] < next_node.val) {
					d[next_node.y][next_node.x][i] = cd;
					visit[next_node.y][next_node.x] = next_node.val;
				}

				cell[next_node.y][next_node.x][i] += next_node.val;
			}
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}