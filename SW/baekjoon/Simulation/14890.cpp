#include <iostream>
#include <ios>

using namespace std;

int map[101][101];
int N, L, ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> L;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> map[y][x];

	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			map[N + x][y] = map[y][x];

	for (int y = 0; y < 2 * N; y++) {
		int chk = 1, x = 0;
		for (x = 0; x < N - 1; x++) {
			if (map[y][x] == map[y][x + 1])
				chk++;
			else if (map[y][x] + 1 == map[y][x + 1] && chk >= L)
				chk = 1;
			else if (map[y][x] - 1 == map[y][x + 1] && chk >= 0)
				chk = -L + 1;
			else
				break;
		}
		if (x == N - 1 && chk >= 0)
			ans++;
	}

	cout << ans << "\n";

	return 0;
}