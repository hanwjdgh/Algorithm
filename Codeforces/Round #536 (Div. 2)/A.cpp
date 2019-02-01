#include <iostream>
#include <ios>

#define MAX 501

using namespace std;

int dir[4][2] = { {-1,-1},{-1,1}, {1,-1},{1,1} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	char matrix[MAX][MAX];

	int N, ans = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];

	if (N < 3)
		cout << ans << "\n";
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (matrix[i][j] == '.')
					continue;

				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dir[k][0], ny = j + dir[k][1];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N || matrix[nx][ny] == '.')
						break;
					cnt++;
				}
				if (cnt == 4)
					ans++;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}