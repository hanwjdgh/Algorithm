#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int H[21];
int T, N, B, ans = 1e9;

void dfs(int idx, int val) {
	if (idx == N) {
		if (val >= B)
			ans = min(ans, val);
		return;
	}

	dfs(idx + 1, val + H[idx]);
	dfs(idx + 1, val);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		cin >> N >> B;

		ans = 1e9;
		for (int i = 0; i < N; i++)
			cin >> H[i];

		dfs(0, 0);

		cout << "#" << t_case << " " << ans - B << "\n";
	}

	return 0;
}