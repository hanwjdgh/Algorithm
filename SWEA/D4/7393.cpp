#include <iostream>
#include <ios>
#include <cstring>

using namespace std;

int mod = 1000000000;
int dp[101][10][1 << 10];
int T, N;

int find(int pos, int start, int number) {
	if (pos == N)
		return number == (1 << 10) - 1 ? 1 : 0;

	int &ret = dp[pos][start][number];

	if (ret != 0)
		return ret;

	if (start - 1 >= 0)
		ret += find(pos + 1, start - 1, number | (1 << (start - 1)));
	if (start + 1 < 10)
		ret += find(pos + 1, start + 1, number | (1 << (start + 1)));

	ret %= mod;

	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int ans = 0;

		memset(dp, 0, sizeof(dp));

		cin >> N;

		for (int i = 1; i <= 9; i++) {
			ans += find(1, i, 1 << i);
			ans %= mod;
		}
	
		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}