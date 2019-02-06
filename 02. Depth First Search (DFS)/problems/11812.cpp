#include <iostream>
#include <ios>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long N, K, Q;
	long long a, b;

	cin >> N >> K >> Q;

	for (int i = 0; i < Q; i++) {
		cin >> a >> b;

		if (K == 1)
			cout << abs(a - b) << "\n";
		else {
			int cnt = 0;

			while (a != b) {
				while (a > b) {
					cnt++;
					a = (a + K - 2) / K;
				}
				while (b > a) {
					cnt++;
					b = (b + K - 2) / K;
				}
			}
			cout << cnt << "\n";
		}
	}

	return 0;
}