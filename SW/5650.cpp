#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

typedef pair <int, int > p;

vector <vector <p > > v(5);
int N, max_v, board[MAX][MAX];
int block[6][4] = { {0,0,0,0},{1,3,0,2},{3,2,0,1},{2,0,3,1},{2,3,1,0},{2,3,0,1} };
int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };

int move(int x, int y, int d) {
	int ret = 0;
	int nx = x + dir[d][0], ny = y + dir[d][1];

	if (nx < 0 || ny < 0 || nx >= N || ny >= N)
		ret = move(x, y, (d + 2) % 4) + 1;

	else {
		int num = board[nx][ny];

		if (num == -1 || num == -2)
			return 0;
		else if (num == 0)
			ret = move(nx, ny, d);
		else if (num >= 1 && num <= 5)
			ret = move(nx, ny, block[num][d]) + 1;
		else {
			if (v[num - 6][0].first == nx && v[num - 6][0].second == ny)
				ret = (v[num - 6][1].first, v[num - 6][1].first, d);
			else
				ret = (v[num - 6][0].first, v[num - 6][0].first, d);
		}
	}
	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		max_v = 0;

		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
				if (board[i][j] > 5)
					v[board[i][j] - 6].push_back({ i,j });
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						board[i][j] = -2;
						max_v = max(max_v, move(i, j, k));
						board[i][j] = 0;
					}
				}
			}
		}

		cout << "#" << t << " " << max_v << "\n";
	}

	return 0;
}