#include <iostream>
#include <ios>

using namespace std;

int ad[51][51];
int num[4];
int T, N, M, ans;

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		num[cnt] = num[0];
		bool err = false;

		for (int i = 0; i < 3; i++) {
			if (!ad[num[i]][num[i + 1]]) {
				err = true;
				break;
			}
		}
		if (!err)
			ans++;

		return;
	}

	for (int i = idx; i <= N; i++) {
		num[cnt] = i;
		dfs(i + 1, cnt + 1);
		num[cnt] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int x, y;

		ans = 0;

		for (int y = 0; y < 51; y++)
			for (int x = 0; x < 51; x++)
				ad[y][x] = 0;

		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			cin >> x >> y;
			ad[x][y] = ad[y][x] = 1;
		}

		dfs(1, 0);

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}