#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

char cycle[4][8];
int K, ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int target, rot;

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 8; x++)
			cin >> cycle[y][x];

	cin >> K;

	while (K--) {
		int move[4] = { 0, };

		cin >> target >> rot;

		target--;
		move[target] = rot;

		for (int i = target; i > 0; i--)
			if (cycle[i][6] != cycle[i - 1][2])
				move[i - 1] = -move[i];

		for (int i = target; i < 3; i++)
			if (cycle[i][2] != cycle[i + 1][6])
				move[i + 1] = -move[i];

		for (int y = 0; y < 4; y++) {
			if (move[y] == 1) {
				char temp = cycle[y][7];
				for (int x = 7; x >= 1; x--)
					cycle[y][x] = cycle[y][x - 1];
				cycle[y][0] = temp;
			}
			else if (move[y] == -1) {
				char temp = cycle[y][0];
				for (int x = 0; x < 7; x++)
					cycle[y][x] = cycle[y][x + 1];
				cycle[y][7] = temp;
			}
		}
	}

	for (int i = 0; i < 4; i++)
		ans += (cycle[i][0] - '0' << i);

	cout << ans << "\n";

	return 0;

}