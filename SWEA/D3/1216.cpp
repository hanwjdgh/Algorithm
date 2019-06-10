#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int fail[1001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; t <= 10; t++) {
		int N, cnt = 1;
		char board[101][101];

		cin >> N;

		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cin >> board[i][j];

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {

				for (int k = 2; k <= 100 - j; k++) {
					int chk = 0, ccnt = 0;
					for (int a = 0; a < k / 2; a++) {
						if (board[i][j + a] != board[i][k - a - 1 + j])
							break;
						else
							chk++;
					}
					if (chk == k / 2)
						cnt = max(cnt, k);

					for (int a = 0; a < k / 2; a++) {
						if (board[j + a][i] != board[k - a - 1 + j][i])
							break;
						else
							ccnt++;
					}
					if (ccnt == k / 2)
						cnt = max(cnt, k);
				}
			}
		}

		cout << "#" << t << " " << cnt << "\n";
	}

	return 0;
}