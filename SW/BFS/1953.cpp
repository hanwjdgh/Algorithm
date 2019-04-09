#include <iostream>
#include <ios>
#include <queue>

using namespace std;

struct Node {
	int y, x;
};

Node node;
int map[51][51][4];
int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
int pipe[8][4] = { { 0,0,0,0 },{ 1,1,1,1 },{ 1,0,1,0 },{ 0,1,0,1 },{ 0,1,1,0 },{ 1,1,0,0 },{ 1,0,0,1 },{ 0,0,1,1 } };
int N, M, R, C, L, num;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int visit[51][51] = { 0, };
		int ans = 1;
		queue <Node > q;
		
		cin >> N >> M >> node.y >> node.x >> L;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				cin >> num;
				
				for (int i = 0; i < 4; i++)
					map[y][x][i] = pipe[num][i];
			}
		}

		visit[node.y][node.x] = 1;
		q.push(node);

		for (int i = 1; i < L; i++) {
			int qs = q.size();
			for (int j = 0; j < qs; j++) {
				Node cur_node = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					if (map[cur_node.y][cur_node.x][k] == 0) 
						continue;
					
					Node next_node;
					next_node.y = cur_node.y + dir[k][0], next_node.x = cur_node.x + dir[k][1];
			
					if (next_node.y < 0 || next_node.x < 0 || next_node.y >= N || next_node.x >= M || visit[next_node.y][next_node.x]) 
						continue;

					if (map[next_node.y][next_node.x][(k + 2) % 4]) {
						ans++;
						q.push(next_node);
						visit[next_node.y][next_node.x] = 1;
					}
				}
			}
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}