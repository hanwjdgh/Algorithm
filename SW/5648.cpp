#include <iostream>
#include <ios>
#include <queue>
#include <cstring>

using namespace std;

struct Atom {
	int y, x, d, e;
};

Atom atom[1001];
int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
int N, board[4001][4001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		memset(board, 0, sizeof(board));
		queue <Atom > q;
		int cnt = 0;

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> atom[i].x >> atom[i].y >> atom[i].d >> atom[i].e;
			atom[i].y = (atom[i].y + 1000) * 2;
			atom[i].x = (atom[i].x + 1000) * 2;
			board[atom[i].y][atom[i].x] = atom[i].e;
			q.push(atom[i]);
		}
		while (!q.empty()) {
			Atom cur_atom = q.front();
			q.pop();

			if (board[cur_atom.y][cur_atom.x] > cur_atom.e) {
				cnt += board[cur_atom.y][cur_atom.x];
				board[cur_atom.y][cur_atom.x] = 0;
				continue;
			}

			Atom next_atom = cur_atom;
			next_atom.y += dir[next_atom.d][0], next_atom.x += dir[next_atom.d][1];

			if (next_atom.y < 0 || next_atom.x < 0 || next_atom.y >= 4001 || next_atom.x >= 4001) {
				board[cur_atom.y][cur_atom.x] = 0;
				continue;
			}

			board[cur_atom.y][cur_atom.x] = 0;
			if (board[next_atom.y][next_atom.x] == 0) {
				board[next_atom.y][next_atom.x] = next_atom.e;
				q.push(next_atom);
			}
			else {
				board[next_atom.y][next_atom.x] += next_atom.e;
			}
		}

		cout << "#" << t_case << " " << cnt << "\n";
	}

	return 0;
}