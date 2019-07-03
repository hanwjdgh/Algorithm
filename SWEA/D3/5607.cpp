#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>

using namespace std;

int mod = 1234567891;
int T, N, R;

long long fermat(long n, int x) {
	if (x == 0) return 1;
	long long tmp = fermat(n, x / 2);
	long long ret = (tmp * tmp) % mod;
	if (x % 2 == 0)
		return ret;
	else
		return (ret * n) % mod;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		vector <long long > v(1000001, 0);

		cin >> N >> R;

		v[0] = 1;
		for (int i = 1; i <= N; i++) 
			v[i] = (v[i - 1] * i) % mod;

		long long bottom = (v[R] * v[N - R]) % mod;
		long long re = fermat(bottom, mod - 2);

		cout << "#" << t_case << " " << ((v[N] * re) % mod) << "\n";
	}

	return 0;
}