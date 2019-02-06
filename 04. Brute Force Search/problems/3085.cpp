#include <iostream>
#include <ios>
#include <algorithm>

#define MAX 51

using namespace std;

char board[MAX][MAX];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int N, max_v;

void check() {
	char temp;
	int cnt;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == 0) {
				temp = board[i][j];
				cnt = 1;
			}
			else {
				if (temp == board[i][j])
					cnt++;
				else {
					max_v = max(max_v, cnt);
					temp = board[i][j];
					cnt = 1;
				}
			}
		}
		max_v = max(max_v, cnt);

		for (int j = 0; j < N; j++) {
			if (j == 0) {
				temp = board[j][i];
				cnt = 1;
			}
			else {
				if (temp == board[j][i])
					cnt++;
				else {
					max_v = max(max_v, cnt);
					temp = board[j][i];
					cnt = 1;
				}
			}
		}
		max_v = max(max_v, cnt);
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			for (int k = 0; k < 4; k++) {
				int nx = i + dir[k][0], ny = j + dir[k][1];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				swap(board[i][j], board[nx][ny]);
				check();
				swap(board[i][j], board[nx][ny]);
			}
		}
	}

	cout << max_v << "\n";

	return 0;
}