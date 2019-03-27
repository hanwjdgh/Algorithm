#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int map[21][21], com, chk;
int N, M, X, Y, K;
int dir[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };
int line[2][4] = { {0,2,3,5},{0,1,4,5} };
int rot[4][4] = {
	{3,0,5,2},
	{2,5,0,3},
	{4,0,5,1},
	{1,5,0,4}
};
int dice[6];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> Y >> X >> K;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> map[y][x];

	for (int i = 0; i < K; i++) {
		cin >> com;

		Y += dir[com][0], X += dir[com][1];
		if (Y < 0 || X < 0 || Y >= N || X >= M) {
			Y -= dir[com][0], X -= dir[com][1];
			continue;
		}

		int temp[4] = { 0, };
		chk = com / 3;

		for (int j = 0; j < 4; j++)
			temp[j] = dice[rot[com - 1][j]];

		for (int j = 0; j < 4; j++)
			dice[line[chk][j]] = temp[j];

		if (map[Y][X] == 0)
			map[Y][X] = dice[5];
		else {
			dice[5] = map[Y][X];
			map[Y][X] = 0;
		}

		cout << dice[0] << "\n";
	}

	return 0;
}