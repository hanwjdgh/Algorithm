#include <iostream>
#include <ios>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
	int y, x, dis;
};

bool operator<(Node a, Node b) {
	if (a.dis > b.dis)
		return true;
	else if (a.dis == b.dis) {
		if (a.x > b.x)
			return true;
	}
	return false;
}

int map[16][16], temp[16][16];
int acher[5];
int N, M, D, ans;

bool check(int Ay) {
	for (int y = 0; y < Ay; y++) {
		for (int x = 0; x < M; x++) {
			if (temp[y][x] == 1)
				return true;
		}
	}
	return false;
}

void dfs(int cur, int cnt) {
	if (cnt == 3) {

		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				temp[y][x] = map[y][x];

		int chk = 0;
		int Ay = N;

		while (Ay > 0) {
			priority_queue <Node > pq[3];

			for (int i = 0; i < 3; i++) {
				int Ax = acher[i];
		
				for (int y = Ay - 1; y >= 0; y--) {
					for (int x = 0; x < M; x++) {
						if (!temp[y][x])
							continue;
						if ((abs(Ay - y) + abs(Ax - x)) <= D) {
							Node next_node;
							next_node.y = y, next_node.x = x, next_node.dis = (abs(Ay - y) + abs(Ax - x));
							pq[i].push(next_node);
						}
					}
				}
			}

			Node node[3];
			int idx = 0;

			for (int i = 0; i < 3; i++) {
				bool find = false;
				while (!pq[i].empty()) {
					Node cur = pq[i].top();
					pq[i].pop();

					if (!temp[cur.y][cur.x] || find)
						continue;
					else {
						node[idx].y = cur.y, node[idx++].x = cur.x;
						find = true;
					}
				}
			}

			for (int i = 0; i < idx; i++) {
				if (!temp[node[i].y][node[i].x])
					continue;
				temp[node[i].y][node[i].x] = 0;
				chk++;
			}

			Ay--;

			if (!check(Ay))
				break;
		}

		ans = max(ans, chk);

		return;
	}

	for (int i = cur + 1; i < M; i++) {
		acher[cnt] = i;
		dfs(i, cnt + 1);
		acher[cnt] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> D;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> map[y][x];

	for (int i = 0; i < 3; i++)
		acher[i] = -1;

	dfs(-1, 0);

	cout << ans << "\n";

	return 0;
}