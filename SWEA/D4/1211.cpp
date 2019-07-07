#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; t <= 10; t++) {
		int N, y;
		int map[102][102];

		cin >> N;

		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cin >> map[i][j];

		int ans = 0;
		int min = 1e9;
		for (int j = 0; j < 100; j++) {
			if (map[0][j] == 1) {
				y = j;
				int cnt = 0;
				for (int i = 0; i < 100; i++) {
					cnt++;
					if (map[i][y + 1] == 1) {
						while (true) {
							y++;
							cnt++;
							if (map[i][y + 1] != 1) {
								break;
							}
						}
					}
					else if (map[i][y - 1] == 1) {
						while (true) {
							y--;
							cnt++;
							if (map[i][y - 1] != 1) {
								break;
							}
						}
					}
				}
				if (cnt <= min) {
					ans = j;
					min = cnt;
				}
			}
		}

		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}