#include <iostream>
#include <ios>
#include <cstring>

using namespace std;

char board[50][50];
int N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int s = 0, ans = 0, t = 1;

		cin >> N;

		memset(board, '0', sizeof(board));

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> board[i][j];

		s = N / 2;

		for (int i = 0; i < N; i++)
			ans += board[i][s] - '0';

		for (int i = s - 1; i > -1; i--) {
			for (int j = t; j < N - t; j++)
				ans += board[j][i] - '0';
			t++;
		}

		t = 1;
		for (int i = s + 1; i < N; i++) {
			for (int j = t; j < N-t; j++) 		
				ans += board[j][i] - '0';
			t++;
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}