#include <iostream>
#include <ios>
#include <string>

using namespace std;

int board[8][8];
int dir[8][2] = { {0,1},{0,-1},{1,0},{-1,0},{-1,1},{-1,-1},{1,1},{1,-1} };
string com[8] = { "R","L","B","T","RT","LT","RB","LB" };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string kp, sp, cm;
	int N, kx, ky, sx, sy;

	cin >> kp >> sp >> N;

	ky = kp[0] - 'A', kx = 8 - (kp[1] - '0');
	sy = sp[0] - 'A', sx = 8 - (sp[1] - '0');

	board[kx][ky] = 1;
	board[sx][sy] = 2;

	for (int i = 0; i < N; i++) {
		cin >> cm;

		int idx;
		for (int j = 0; j < 8; j++) {
			if (cm == com[j]) {
				idx = j;
				break;
			}
		}
		int nkx = kx + dir[idx][0], nky = ky + dir[idx][1];

		if (nkx < 0 || nky < 0 || nkx >= 8 || nky >= 8)
			continue;
		if (board[nkx][nky] == 2) {
			int nsx = sx + dir[idx][0], nsy = sy + dir[idx][1];
			if (nsx < 0 || nsy < 0 || nsx >= 8 || nsy >= 8)
				continue;
			board[nsx][nsy] = 2, board[sx][sy] = 0;
			sx = nsx, sy = nsy;

		}
		board[nkx][nky] = 1, board[kx][ky] = 0;
		kx = nkx, ky = nky;
	}

	string kf = "", sf = "";

	kf += (char)(ky + 'A');
	kf += 8 - kx + '0';

	sf += (char)(sy + 'A');
	sf += 8 - sx + '0';

	cout << kf << "\n";
	cout << sf << "\n";

	return 0;
}