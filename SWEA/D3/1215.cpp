#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; t <= 10; t++) {
		int N, cnt = 0;
		char board[9][9];

		cin >> N;

		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				cin >> board[i][j];

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8 - N + 1; j++) {
				int chk = 0;
				
				for (int k = 0; k < N/2; k++) {
					if (board[i][j + k] != board[i][N - k - 1 + j])
						break;
					else
						chk++;
				}
				if (chk == N / 2) 
					cnt++;
			}
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8 - N + 1; j++) {
				int chk = 0;

				for (int k = 0; k < N / 2; k++) {
					if (board[j + k][i] != board[N - k - 1 + j][i])
						break;
					else
						chk++;
				}
				if (chk == N / 2)
					cnt++;
			}
		}
		

		cout << "#" << t << " " << cnt << "\n";
	}

	return 0;
}