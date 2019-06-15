#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int Tr[1001], Kr[1001];
int visit[1001];
int T, N, L, ans;

void dfs(int idx, int val, int temp) {
	if (idx == N) {
		if (val <= L)
			ans = max(ans, temp);
		return;
	}

	dfs(idx + 1, val + Kr[idx], temp + Tr[idx]);
	dfs(idx + 1, val, temp);

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;

		cin >> N >> L;

		for (int i = 0; i < N; i++)
			cin >> Tr[i] >> Kr[i];

		dfs(0, 0, 0);

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}