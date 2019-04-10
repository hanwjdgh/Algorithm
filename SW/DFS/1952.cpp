#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int cost[4], usep[12];
int ans;

void dfs(int cur, int val) {
	if (val >= ans)
		return;

	if (cur == 12) {
		ans = min(ans, val);
		return;
	}

	if (usep[cur] == 0)
		dfs(cur + 1, val);
	else {
		int ncur, temp;
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				ncur = cur + 1;
				temp = (cost[i] * usep[cur]);
			}
			else if (i == 1) {
				ncur = cur + 1;
				temp = cost[i];
			}
			else {
				if (ncur > 9)
					ncur = 12;
				else
					ncur = cur + 3;
				temp = cost[i];
			}
			dfs(ncur, val + temp);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 1e9;

		for (int i = 0; i < 4; i++)
			cin >> cost[i];

		for (int i = 0; i < 12; i++)
			cin >> usep[i];

		dfs(0, 0);

		ans = min(ans, cost[3]);

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}