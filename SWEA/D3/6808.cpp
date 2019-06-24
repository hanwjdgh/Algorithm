#include <iostream>
#include <ios>

using namespace std;

int kyu[9], iny[9];
int visit[9];
int T, wans, lans;

void dfs(int cnt, int ksum, int isum) {
	if (cnt == 9) {
		if (ksum > isum)
			wans++;
		else
			lans++;
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (visit[i])
			continue;

		visit[i] = 1;
		if (kyu[cnt] > iny[i])
			dfs(cnt + 1, ksum + (kyu[cnt] + iny[i]), isum);
		else
			dfs(cnt + 1, ksum, isum + (kyu[cnt] + iny[i]));
		visit[i] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int chk[19] = { 0, };
		int idx = 0;
		wans = lans = 0;

		for (int i = 0; i < 9; i++) {
			cin >> kyu[i];
			chk[kyu[i]] = 1;
		}

		for (int i = 1; i <= 18; i++) {
			if (chk[i])
				continue;
			iny[idx++] = i;
		}

		dfs(0, 0, 0);

		cout << "#" << t_case << " " << wans << " " << lans << "\n";

	}

	return 0;
}