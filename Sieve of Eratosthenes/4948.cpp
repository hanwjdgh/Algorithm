#include <iostream>
#include <ios>
#include <vector>

#define MAX 246914

using namespace std;

bool prime[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;

	while (1) {
		int cnt = 0;
		fill(prime, prime + MAX, false);

		cin >> N;

		if (N == 0)
			break;

		prime[1] = true;
		for (int i = 2; i <= 2 * N; i++) {
			if (prime[i])
				continue;
			for (int j = i * 2; j <= 2 * N; j += i) {
				if (prime[j])
					continue;
				prime[j] = true;
			}
		}
		for (int i = N + 1; i <= 2 * N; i++)
			if (!prime[i])
				cnt++;
		cout << cnt << "\n";
	}
	return 0;
}