#include <iostream>
#include <ios>

#define MAX 21

using namespace std;

int map[MAX][MAX];
int dir[4][2] = { { 0,1 },{ 0,-1 },{ -1,0 },{ 1,0 } };
int arr[7], temp[7];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, x, y, K;
	int d;

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < K; i++) {
		cin >> d;
		int nx = x + dir[d - 1][0], ny = y + dir[d - 1][1];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			continue;

		for (int i = 1; i < 7; i++)
			temp[i] = arr[i];

		if (d == 1) {
			arr[1] = temp[4];
			arr[3] = temp[1];
			arr[4] = temp[6];
			arr[6] = temp[3];
		}
		else if (d == 2) {
			arr[1] = temp[3];
			arr[3] = temp[6];
			arr[4] = temp[1];
			arr[6] = temp[4];
		}
		else if (d == 3) {
			arr[1] = temp[5];
			arr[2] = temp[1];
			arr[5] = temp[6];
			arr[6] = temp[2];
		}
		else {
			arr[1] = temp[2];
			arr[2] = temp[6];
			arr[5] = temp[1];
			arr[6] = temp[5];
		}
		if (map[nx][ny] == 0)
			map[nx][ny] = arr[6];
		else {
			arr[6] = map[nx][ny];
			map[nx][ny] = 0;
		}
		x = nx;
		y = ny;
		cout << arr[1] << "\n";
	}
	return 0;
}