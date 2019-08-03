#include <iostream>
#include <ios>
#include <cmath>

#define MOD 1000000007

using namespace std;

int T, N;
long long dp[1000001];

long long cal(int cur) {
	long long ret = 1, fac = cur;
	int temp = cur;

	while (temp > 0) {
		if (temp % 2 == 1)
			ret *= fac;

		temp /= 2;
		fac *= fac;
		fac %= MOD;
		ret %= MOD;
	}

	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	dp[1] = 1;
	for (int i = 2; i <= 1000000; i++)
		dp[i] = (dp[i - 1] + cal(i)) % MOD;

	for (int t_case = 1; t_case <= T; t_case++) {

		cin >> N;

		cout << "#" << t_case << " " << dp[N] << "\n";
	}

	return 0;
}