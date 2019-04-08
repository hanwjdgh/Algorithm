#include <iostream>
#include <ios>

using namespace std;

int arr[21][21];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int N, X, ans = 0;

		cin >> N >> X;

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> arr[y][x];

		for (int x = 0; x < N; x++) 
			for (int y = 0; y < N; y++) 
				arr[N + x][y] = arr[y][x];

		for (int y = 0; y < 2 * N; y++) {
			int chk = 1, x = 0;
			for (x = 0; x < N - 1; x++) {
				if (arr[y][x] == arr[y][x + 1])
					chk++;
				else if (arr[y][x] + 1 == arr[y][x + 1] && chk >= X)
					chk = 1;
				else if (arr[y][x] - 1 == arr[y][x + 1] && chk >= 0)
					chk = -X + 1;
				else
					break;
			}
			if (x == N - 1 && chk >= 0)
				ans++;
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;

}