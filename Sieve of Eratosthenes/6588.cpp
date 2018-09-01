#include <iostream>
#include <ios>
#include <vector>

#define MAX 1000001

using namespace std;

bool prime[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	prime[0] = prime[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (prime[i])
			continue;
		for (int j = i * i; j <= MAX; j += i) {
			if (prime[j])
				continue;
			prime[j] = true;
		}
	}

	int N;

	while (1) {
		int a, b;
		cin >> N;

		if (N == 0)
			break;

		a = b = 0;
		for (int i = 0; i <= N / 2; i++) {
			if (!prime[i] && !prime[N - i]) {
				a = i, b = N - i;
				break;
			}
		}
		if (a == 0)
			cout << "Goldbach's conjecture is wrong." << "\n";
		else
			cout << N << " = " << a << " + " << b << "\n";
	}
	return 0;
}