#include <iostream>
#include <ios>
#include <algorithm>
#include <string>

using namespace std;

struct Card {
	char M;
	int N;
}card[7];

int T, min_v;
int pattern[4], tnum[14], num[4][14];
int chk[9], visit[9];
string ans[9] = { "Straight Flush", "4 Card", "Full House", "Flush", "Straight", "Triple", "2 Pair", "1 Pair", "Top" };

void init() {
	for (int i = 0; i < 9; i++)
		chk[i] = 0;

	for (int i = 0; i < 4; i++)
		pattern[i] = 0;

	for (int i = 0; i < 14; i++)
		tnum[i] = 0;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 14; j++)
			num[i][j] = 0;
}

void choice(int cnt, int idx) {
	if (cnt == 5) {
		init();
		for (int i = 0; i < cnt; i++) {
			int idx = 0, pos = visit[i];

			switch (card[pos].M) {
			case 'S':
				idx = 0;
				break;
			case 'D':
				idx = 1;
				break;
			case 'H':
				idx = 2;
				break;
			case 'C':
				idx = 3;
				break;
			default:
				break;
			}

			pattern[idx]++;

			if (card[pos].N == 1) {
				num[idx][0]++;
				tnum[0]++;
			}

			num[idx][card[pos].N]++;
			tnum[card[pos].N]++;
		}

		chk[8] = 1;

		for (int i = 1; i <= 13; i++) {
			if (tnum[i] < 2)
				continue;

			if (tnum[i] == 2)
				chk[7]++;
			else if (tnum[i] == 3)
				chk[5]++;
			else
				chk[1]++;

			tnum[i] = 1;
		}

		tnum[0] = 1;
		chk[6] = (chk[7] > 1) ? 1 : 0;
		chk[2] = (chk[7] && chk[5]) ? 1 : 0;

		for (int i = 0; i < 4; i++) {
			if (pattern[i] == 5) {
				chk[3] = i + 10;
				break;
			}
		}

		for (int i = 1; i <= 10; i++) {
			int sum = tnum[i % 14] + tnum[(i + 1) % 14] + tnum[(i + 2) % 14] + tnum[(i + 3) % 14] + tnum[(i + 4) % 14];
			if (sum == 5) {
				chk[4] = 1;
				break;
			}
		}

		for (int i = 0; i < 4; i++) {
			bool find = false;
			for (int j = 1; j <= 10; j++) {
				int sum = num[i][j % 14] + num[i][(j + 1) % 14] + num[i][(j + 2) % 14] + num[i][(j + 3) % 14] + num[i][(j + 4) % 14];
				if (sum == 5) {
					chk[4] = i + 10;
					find = true;
					break;
				}
			}
			if (find)
				break;
		}

		chk[0] = (chk[4] > 1 && (chk[3] == chk[4])) ? 1 : 0;

		int temp = 0;
		for (int i = 0; i < 9; i++) {
			if (chk[i] != 0) {
				temp = i;
				break;
			}
		}

		min_v = min(min_v, temp);
		return;
	}

	for (int i = idx; i < 7; i++) {
		visit[cnt] = i;
		choice(cnt + 1, i + 1);
		visit[cnt] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		min_v = 8;

		for (int i = 0; i < 7; i++)
			cin >> card[i].M >> card[i].N;

		choice(0, 0);

		cout << "#" << t_case << " " << ans[min_v] << "\n";
	}
	return 0;
}