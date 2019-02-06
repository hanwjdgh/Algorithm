#include <iostream>
#include <ios>
#include <algorithm>

#define MAX 51

using namespace std;

char board[MAX][MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int answer = 2600;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			int cnt = 0;

			for (int a = 0; a < 8; a++) 
				for (int b = 0; b < 8; b++) 
					cnt += ((a % 2 == b % 2) ? 'W' : 'B') == board[i + a][j + b];
			answer = min(answer, cnt);
			answer = min(answer, abs(64 - cnt));
		}
	}

	cout << answer << "\n";

	return 0;
}