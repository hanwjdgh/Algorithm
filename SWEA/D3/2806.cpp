#include <iostream>
#include <ios>
#include <cmath>

using namespace std;

int N, ans, q[11];

void backtrack(int cur, int cnt) {
	for (int i = 0; i < cnt; i++) {
		if (q[i] == cur || abs(cur - q[i]) == cnt - i)
			return;
	}

	if (cnt == N - 1) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		q[cnt + 1] = i;
		backtrack(i, cnt + 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;
		fill(q, q + 11, 0);

		cin >> N;

		for (int i = 0; i < N; i++) {
			q[0] = i;
			backtrack(i, 0);
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}