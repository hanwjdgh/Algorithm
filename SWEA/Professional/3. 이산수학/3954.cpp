#include <iostream>
#include <ios>
#include <cmath>

#define MAX 1000001

using namespace std;

int T, a, b;
long long prime[MAX + 1];
long long euler[MAX + 1];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	prime[0] = prime[1] = 1;

	for (long long i = 2; i <= MAX; i++) {
		if (!prime[i]) {
			prime[i] = i;
			for (long long j = i; j * i <= MAX; j++) {
				prime[j * i] = i;
			}
		}
	}

	euler[1] = 1;
	for (long long i = 1; i <= MAX; i++) {
		long long int tmp = 1;
		long long num = i;

		while (num > 1) {
			long long p = prime[num], e = 0;

			while (num % p == 0) {
				num /= p, e++;
			}
			tmp *= ((p - 1) * (pow((double)p, e - 1)));
		}
		euler[i] = tmp + euler[i - 1];
	}

	for (int t_case = 1; t_case <= T; t_case++) {

		long long ans = 0;

		cin >> a >> b;
		
		ans = euler[b] - euler[a - 1];

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}