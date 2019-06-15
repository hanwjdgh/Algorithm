#include <iostream>
#include <ios>

using namespace std;

int chk[1001], prime[1001];
int visit[3];
int T, N, idx, ans;

void dfs(int id, int cnt, int val) {
	if (val > N)
		return;

	if (cnt == 3) {
		if (val == N) 
			ans++;
		return;
	}

	for (int i = id; i < idx; i++) {
		if (val + prime[i] > N)
			break;
		visit[cnt] = prime[i];
		dfs(i, cnt + 1, val + prime[i]);
		visit[cnt] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int i = 2; i <= 1000; i++) {
		if (chk[i])
			continue;
		prime[idx++] = i;
		for (int j = i * 2; j <= 1000; j += i)
			chk[j] = 1;
	}

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;

		cin >> N;

		dfs(0, 0, 0);

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}   