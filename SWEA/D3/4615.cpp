#include <iostream>
#include <ios>
#include <cstring>

#define MAX 9

using namespace std;

int dir[8][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 },{-1,-1},{-1,1},{1,-1},{1,1} };
int board[MAX][MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		memset(board, 0, sizeof(board));
		int N, M, a, b, s;

		cin >> N >> M;

		board[(N + 1) / 3][(N + 1) / 3] = board[N / 2][N / 2] = 2;
		board[(N + 1) / 3][N / 2] = board[N / 2][(N + 1) / 3] = 1;

		for (int i = 0; i < M; i++) {
			cin >> a >> b >> s;
			board[a - 1][b - 1] = s;

			for (int j = 0; j < 8; j++) {
				bool find = false;
				int nx = (a - 1) + dir[j][0], ny = (b - 1) + dir[j][1];
				while (1) {
					if (nx < 0 || ny < 0 || nx >= N || ny >= N || board[nx][ny] == 0)
						break;

					if (board[nx][ny] == s) {
						find = true;
						break;
					}
					nx += dir[j][0];
					ny += dir[j][1];
				}

				while (find) {
					if (nx == (a - 1) && ny == (b - 1))
						break;
					board[nx][ny] = s;
					nx -= dir[j][0];
					ny -= dir[j][1];
				}
			}
		}

		int white = 0, black = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 1)
					black++;
				else if (board[i][j] == 2)
					white++;
			}
		}
		cout << "#" << t_case << " " << black << " " << white << "\n";
	}

	return 0;

}