#include <iostream>
#include <ios>

using namespace std;

struct Node {
	int y, x, cnt, d;
};

Node node[1001];
int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
int N, K, M, ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		cin >> N >> M >> K;

		for (int i = 1; i <= K; i++) {
			cin >> node[i].y >> node[i].x >> node[i].cnt >> node[i].d;
			--node[i].d;
			q.push(node[i]);
		}

		while(M--) {
			int map[101][101][2] = { 0, };

			for (int i = 1; i <= K; i++) {
				if (node[i].cnt == 0)
					continue;

				node[i].y += dir[node[i].d][0], node[i].x += dir[node[i].d][1];

				if (node[i].y == 0 || node[i].x == 0 || node[i].y == N - 1 || node[i].x == N - 1) {
					node[i].cnt /= 2, node[i].d = (5 - node[i].d) % 4;
				}

				if (map[node[i].y][node[i].x][0]) {
					int tidx = map[node[i].y][node[i].x][0];

					node[tidx].cnt += node[i].cnt;

					if (map[node[i].y][node[i].x][1] < node[i].cnt) {
						map[node[i].y][node[i].x][1] = node[i].cnt;
						node[tidx].d = node[i].d;
					}
					node[i].cnt = 0;
				}
				else {
					map[node[i].y][node[i].x][0] = i;
					map[node[i].y][node[i].x][1] = node[i].cnt;
				}
			}
			
		}

		for (int i = 1; i <= K; i++)
			ans += node[i].cnt;

		cout << "#" << t_case << " " << ans << "\n";
		
		ans = 0;
	}

	return 0;
}