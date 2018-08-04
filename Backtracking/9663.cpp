#include <iostream>
#include <ios>
#include <cmath>

using namespace std;

int N, ans, board[15][15] = { 0, };
int pos[16] = { 0, };

void backtrack(int x, int cnt) {
	for (int i = 0; i < cnt; i++) {
		if (pos[i] == x || abs(x - pos[i]) == cnt - i) {
			return;
		}
	}

	if (cnt == N - 1) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		pos[cnt + 1] = i;
		backtrack(i, cnt + 1);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		pos[0] = i;
		backtrack(i, 0);
	}
	cout << ans << "\n";
	return 0;
}