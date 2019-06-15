#include <iostream>
#include <ios>

using namespace std;

int num[21];
int T, N, K, ans;

void dfs(int idx, int val) {
	if (val > K)
		return;

	if (val == K) {
		ans++;
		return;
	}

	for (int i = idx; i < N; i++) 
		dfs(i + 1, val + num[i]);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;

		cin >> N >> K;

		for (int i = 0; i < N; i++)
			cin >> num[i];

		dfs(0, 0);

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}