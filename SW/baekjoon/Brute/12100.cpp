#include <iostream>
#include <ios>
#include <algorithm>
#include <queue>

using namespace std;

int N, board[21][21], visit[6], temp[21][21], max_v;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

void move_arr(int d) {
	queue <int > q;

	if (d == 0) {
		for (int y = 0; y < N; y++) {
			for (int x = N - 1; x > -1; x--) {
				if (temp[y][x] == 0)
					continue;
				q.push(temp[y][x]);
				temp[y][x] = 0;
			}
			int idx = N - 1;

			while (!q.empty()) {
				int cur = q.front();
				q.pop();

				if (temp[y][idx] == 0)
					temp[y][idx] = cur;
				else if (temp[y][idx] == cur) {
					temp[y][idx] *= 2;
					--idx;
				}
				else 
					temp[y][--idx] = cur;
			}
		}
	}

	else if (d == 1) {
		for (int x = 0; x < N; x++) {
			for (int y = N-1; y > -1; y--) {
				if (temp[y][x] == 0)
					continue;
				q.push(temp[y][x]);
				temp[y][x] = 0;
			}
			int idx = N - 1;

			while (!q.empty()) {
				int cur = q.front();
				q.pop();

				if (temp[idx][x] == 0)
					temp[idx][x] = cur;
				else if (temp[idx][x] == cur) {
					temp[idx][x] *= 2;
					--idx;
				}
				else
					temp[--idx][x] = cur;
			}
		}
	}

	else if (d == 2) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (temp[y][x] == 0)
					continue;
				q.push(temp[y][x]);
				temp[y][x] = 0;
			}

			int idx = 0;

			while (!q.empty()) {
				int cur = q.front();
				q.pop();

				if (temp[y][idx] == 0)
					temp[y][idx] = cur;
				else if (temp[y][idx] == cur) {
					temp[y][idx] *= 2;
					++idx;
				}
				else
					temp[y][++idx] = cur;
			}
		}
	}

	else {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (temp[y][x] == 0)
					continue;
				q.push(temp[y][x]);
				temp[y][x] = 0;
			}

			int idx = 0;

			while (!q.empty()) {
				int cur = q.front();
				q.pop();

				if (temp[idx][x] == 0)
					temp[idx][x] = cur;
				else if (temp[idx][x] == cur) {
					temp[idx][x] *= 2;
					++idx;
				}
				else
					temp[++idx][x] = cur;
			}
		}
	}
}

void dfs(int cnt) {
	if (cnt == 5) {
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				temp[y][x] = board[y][x];

		for (int i = 0; i < cnt; i++)
			move_arr(visit[i]);

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				max_v = max(max_v, temp[y][x]);
		return;
	}

	for (int i = 0; i < 4; i++) {
		visit[cnt] = i;
		dfs(cnt + 1);
		visit[cnt] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> board[y][x];
	dfs(0);

	cout << max_v << "\n";

	return 0;
}