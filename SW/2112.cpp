#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int film[14][21], visit[14];
int D, W, K, min_v;

void dfs(int cnt, int num) {
	if (num >= min_v)
		return;
	if (cnt == D) {
		int temp[14][21];

		for (int y = 0; y < D; y++)
			for (int x = 0; x < W; x++)
				temp[y][x] = film[y][x];

		for (int i = 0; i < cnt; i++) {
			if (visit[i] == 0)
				continue;
			for (int j = 0; j < W; j++)
				temp[i][j] = visit[i];
		}

		bool err = false;
		for (int y = 0; y < W; y++) {
			int chk = 1;
			for (int x = 0; x < D - 1; x++) {
				if (temp[x][y] == temp[x + 1][y])
					chk++;
				else
					chk = 1;
				if (chk == K)
					break;
			}
			if (chk != K) {
				err = true;
				break;
			}
		}

		if (!err)
			min_v = min(min_v, num);

		return;
	}

	for (int i = 0; i < 3; i++) {
		visit[cnt] = i;
		if (i == 0)
			dfs(cnt + 1, num);
		else
			dfs(cnt + 1, num + 1);
		visit[cnt] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		cin >> D >> W >> K;

		min_v = D + 1;
		for (int y = 0; y < D; y++) {
			for (int x = 0; x < W; x++) {
				cin >> film[y][x];
				film[y][x]++;
			}
		}

		dfs(0, 0);

		cout << "#" << t_case << " " << min_v << "\n";
	}

	return 0;
}
