#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

typedef pair <int, int > p;

vector <vector <p > > v;
int N, max_v, board[MAX][MAX];
int block[6][4] = { { 0,0,0,0 },{ 1,3,0,2 },{ 3,2,0,1 },{ 2,0,3,1 },{ 2,3,1,0 },{ 2,3,0,1 } };
int dir[4][2] = { { 0,-1 },{ -1,0 },{ 0,1 },{ 1,0 } };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		v.clear();
		v.resize(5);
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
						int cnt = 0, d = k, nx = i, ny = j;

						while (1) {
							nx += dir[d][0], ny += dir[d][1];
							if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
								cnt++;
								d = (d + 2) % 4;
							}

							else {
								int num = board[nx][ny];

								if (num == -1 || num == -2) 
									break;
								else if (num == 0)
									continue;
								else if (num >= 1 && num <= 5) {
									cnt++;
									d = block[num][d];
								}
								else {
									if (v[num - 6][0].first == nx && v[num - 6][0].second == ny)
										nx = v[num - 6][1].first, ny = v[num - 6][1].second;
									else
										nx = v[num - 6][0].first, ny = v[num - 6][0].second;
								}
							}
						}

						max_v = max(max_v, cnt);
						board[i][j] = 0;
					}
				}
			}
		}

		cout << "#" << t << " " << max_v << "\n";
	}

	return 0;
}