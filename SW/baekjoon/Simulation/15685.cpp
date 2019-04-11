#include <iostream>
#include <ios>

using namespace std;

int arr[101][101];
int dir[4][2] = { { 0,1 },{ -1,0 },{ 0,-1 },{ 1,0 } };
int conv[4] = { 1,2,3,0 };
int N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y, d, g;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;

		arr[y][x] = 1;
		int temp[1025] = { 0, };
		int rot = 1;
		temp[0] = d;

		for (int j = 0; j < g; j++) {
			for (int k = rot - 1; k > -1; k--) {
				int idx = rot * 2 - 1 - k;
				temp[idx] = conv[temp[k]];
			}
			rot *= 2;
		}

		for (int j = 0; j < rot; j++) {
			y += dir[temp[j]][0], x += dir[temp[j]][1];
			arr[y][x] = 1;
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