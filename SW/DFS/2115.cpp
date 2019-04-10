#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

struct Node {
	int y, x;
};

Node node[2];
int map[11][11], visit[11][11];
int N, M, C, ans, tsum;

bool check(int cy, int cx) {
	for (int x = 0; x < M; x++) {
		int nx = cx + x;
		if (visit[cy][nx])
			return false;
		if (nx >= N)
			return false;
	}
	return true;
}

void visited(int cy, int cx, int idx) {
	for (int x = 0; x < M; x++)
		visit[cy][cx + x] = idx;
}

void find(int cur, int idx, int cnt, int sum) {
	if (cur == M) {
		if (cnt <= C)
			tsum = max(tsum, sum);
		return;
	}
	find(cur + 1, idx, cnt + map[node[idx].y][node[idx].x + cur], sum + pow(map[node[idx].y][node[idx].x + cur], 2));
	find(cur + 1, idx, cnt, sum);
}

void dfs(int cur, int cy, int cx) {
	if (cur == 2) {
		int val = 0;

		for (int i = 0; i < cur; i++) {
			int temp = 0, cnt = 0;
			for (int x = 0; x < M; x++) {
				temp += map[node[i].y][node[i].x + x];
				cnt += pow(map[node[i].y][node[i].x + x], 2);
			}
			if (temp <= C)
				val += cnt;
			else {
				tsum = 0;
				find(0, i, 0, 0);
				val += tsum;
			}
		}
		ans = max(ans, val);
		return;
	}

	if (cy == N)
		return;

	for (int y = cy; y < N; y++) {
		for (int x = cx; x < N; x++) {
			if (check(y, x)) {
				node[cur].y = y, node[cur].x = x;
				visited(y, x, 1);
				dfs(cur + 1, y, x);
				visited(y, x, 0);
			}
		}
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		cin >> N >> M >> C;

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> map[y][x];

		dfs(0, 0, 0);

		cout << "#" << t_case << " " << ans << "\n";

		ans = 0;
	}

	return 0;
}