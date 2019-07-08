#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; t <= 10; t++) {
		int N, x, y;
		int map[101][101];

		cin >> N;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
				if (map[i][j] == 2) {
					x = i, y = j;
				}
			}
		}

		for (int i = 99; i >= 0; i--) {
			if (map[i][y + 1] == 1) {
				while (1) {
					y++;
					if (map[i][y + 1] != 1)
						break;
				}
			}
			else if (map[i][y - 1] == 1) {
				while (1) {
					y--;
					if (map[i][y - 1] != 1)
						break;
				}
			}
		}

		cout << "#" << t << " " << y << "\n";
	}

	return 0;
}