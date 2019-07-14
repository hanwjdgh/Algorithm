#include <iostream>
#include <ios>
#include <string>
#include <queue>

using namespace std;

int T, N, ans, d;
string des[4] = { "left", "right", "up", "down" };
int dir[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
int board[21][21];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;
		queue <int > q;
		string str;

		cin >> N >> str;

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> board[y][x];

		for (int i = 0; i < 4; i++) {
			if (str == des[i])
				d = i;
		}

		if (d == 0) {
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					if (board[y][x] == 0)
						continue;
					q.push(board[y][x]);
					board[y][x] = 0;
				}

				int idx = 0;

				while (!q.empty()) {
					int cur = q.front();
					q.pop();

					if (board[y][idx] == 0)
						board[y][idx] = cur;
					else if (board[y][idx] == cur) {
						board[y][idx] *= 2;
						idx++;
					}
					else
						board[y][++idx] = cur;
				}
			}
		}

		else if (d == 1) {
			for (int y = 0; y < N; y++) {
				for (int x = N - 1; x > -1; x--) {
					if (board[y][x] == 0)
						continue;
					q.push(board[y][x]);
					board[y][x] = 0;
				}

				int idx = N - 1;

				while (!q.empty()) {
					int cur = q.front();
					q.pop();

					if (board[y][idx] == 0)
						board[y][idx] = cur;
					else if (board[y][idx] == cur) {
						board[y][idx] *= 2;
						idx--;
					}
					else
						board[y][--idx] = cur;
				}

			}
		}

		else if (d == 2) {
			for (int x = 0; x < N; x++) {
				for (int y = 0; y < N; y++) {
					if (board[y][x] == 0)
						continue;
					q.push(board[y][x]);
					board[y][x] = 0;
				}

				int idx = 0;

				while (!q.empty()) {
					int cur = q.front();
					q.pop();

					if (board[idx][x] == 0)
						board[idx][x] = cur;
					else if (board[idx][x] == cur) {
						board[idx][x] *= 2;
						idx++;
					}
					else
						board[++idx][x] = cur;
				}
			}

		}

		else {
			for (int x = 0; x < N; x++) {
				for (int y = N - 1; y > -1; y--) {
					if (board[y][x] == 0)
						continue;
					q.push(board[y][x]);
					board[y][x] = 0;
				}

				int idx = N - 1;

				while (!q.empty()) {
					int cur = q.front();
					q.pop();

					if (board[idx][x] == 0)
						board[idx][x] = cur;
					else if (board[idx][x] == cur) {
						board[idx][x] *= 2;
						idx--;
					}
					else
						board[--idx][x] = cur;
				}
			}
		}

		cout << "#" << t_case << "\n";

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++)
				cout << board[y][x] << " ";
			cout << "\n";
		}
	}

	return 0;
}