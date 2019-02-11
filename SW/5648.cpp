#include <iostream>
#include <ios>
#include <cstring>

#define MAX 4001

using namespace std;

int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
int N, board[MAX][MAX];
int atom[1001][4];

void remove(int idx) {
	atom[idx][0] = atom[N - 1][0];
	atom[idx][1] = atom[N - 1][1];
	atom[idx][2] = atom[N - 1][2];
	atom[idx][3] = atom[N - 1][3];
	--N;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		memset(board, 0, sizeof(board));
		int x, y, d, e;
		int cnt = 0;

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> x >> y >> d >> e;
			atom[i][0] = (y + 1000) * 2;
			atom[i][1] = (x + 1000) * 2;
			atom[i][2] = d;
			atom[i][3] = e;
			board[(y + 1000) * 2][(x + 1000) * 2] = e;
		}
	
		for (int i = 0; i <= MAX; i++) {
			int q_size = N;
			if (q_size == 0)
				break;
			for (int j = 0; j < q_size; j++) {
				int cx = atom[j][0], cy = atom[j][1], cd = atom[j][2], ce = atom[j][3];

				if (board[cx][cy] > ce) {
					cnt += board[cx][cy];
					board[cx][cy] = 0;
					remove(j);
					continue;
				}

				int nx = cx + dir[cd][0], ny = cy + dir[cd][1];
			
				if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX) {
					board[cx][cy] = 0;
					continue;
				}
				atom[j][0] = nx, atom[j][1] = ny;
				if (board[nx][ny] == 0) {
					board[cx][cy] = 0;
					board[nx][ny] = ce;
				}
				else {
					board[cx][cy] = 0;
					board[nx][ny] += ce;
					remove(j);
				}
			}
		}

		cout << "#" << t_case << " " << cnt << "\n";
	}

	return 0;
}