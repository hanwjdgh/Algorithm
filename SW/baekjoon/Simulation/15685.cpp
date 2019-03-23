#include <iostream>
#include <ios>
#include <vector>

using namespace std;

int arr[101][101];
int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int x, y, d, g;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> y >> x >> d >> g;

		arr[x][y] = 1;
		vector <int > v;
		v.push_back(d);
		while (g--) {
			for (int j = v.size() - 1; j > -1; j--) {
				v.push_back((v[j] + 1) % 4);
			}
		}
		for (auto n : v) {
			x += dir[n][0], y += dir[n][1];
			arr[x][y] = 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1])
				ans++;

	cout << ans << "\n";

	return 0;
}