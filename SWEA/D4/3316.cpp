#include <iostream>
#include <ios>
#include <string>

using namespace std;

char str[10001];
int T, dp[10001][16], mod = 1000000007;

int dfs(int here, int last) {
	if (str[here] == '\0')
		return 1;

	int &ret = dp[here][last];

	if (ret != 0)
		return ret;

	int a = 3 - (str[here] - 65);

	for (int i = 1; i <= 15; ++i)
		if ((i & last) && ((1 << a) & i))
			ret = (ret + dfs(here + 1, i)) % mod;

	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		cin >> str;

		for (int i = 0; i < 10001; i++)
			for (int j = 1; j <= 15; j++)
				dp[i][j] = 0;

		cout << "#" << t_case << " " << dfs(0, 8) << "\n";
	}

	return 0;
}