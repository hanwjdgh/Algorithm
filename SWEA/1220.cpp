#include <iostream>
#include <ios>
#include <queue>

using namespace std;

typedef struct Node {
	int y, x;
}node;

int board[101][101], N, ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t_case = 1; t_case <= 10; t_case++) {
		int temp[101][101] = { 0, };

		queue <node> Nq, Sq;

		ans = 0;

		cin >> N;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> board[y][x];

				if (board[y][x] == 1)
					Nq.push({ y,x });
				if (board[y][x] == 2)
					Sq.push({ y,x });
			}
		}


		while (!Nq.empty() || !Sq.empty()) {
			int Nsize = Nq.size(), Ssize = Sq.size();

			for (int i = 0; i < Nsize; i++) {
				int cy = Nq.front().y, cx = Nq.front().x;
				Nq.pop();

				cy += 1;

				if (cy >= N) {
					board[cy - 1][cx] = 0;
					continue;
				}
				if (board[cy][cx] == 0) {
					board[cy][cx] = 1;
					board[cy - 1][cx] = 0;
					Nq.push({ cy,cx });
				}
			}

			for (int i = 0; i < Ssize; i++) {
				int cy = Sq.front().y, cx = Sq.front().x;
				Sq.pop();

				cy -= 1;

				if (cy < 0) {
					board[cy + 1][cx] = 0;
					continue;
				}

				if (board[cy][cx] == 0) {
					board[cy][cx] = 2;
					board[cy + 1][cx] = 0;
					Sq.push({ cy,cx });
				}
			}
		}

		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (board[y][x] == 0)
					continue;

				if (board[y][x] == 1 && board[y + 1][x] == 2)
					ans++;
			}
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}