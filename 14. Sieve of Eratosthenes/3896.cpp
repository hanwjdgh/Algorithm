#include <iostream>
#include <ios>
#include <vector>

#define MAX 1299710

using namespace std;

bool prime[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	prime[1] = false;
	for (int i = 2; i <= MAX; i++) {
		if (prime[i])
			continue;
		for (int j = i * 2; j <= MAX; j += i) {
			if (prime[j])
				continue;
			prime[j] = true;
		}
	}

	cin >> T;

	while (T--) {
		int N;

		cin >> N;

		if (!prime[N])
			cout << "0" << "\n";
		else {
			int cnt = 0;
			for (int j = N; prime[j]; j--) 
				cnt++;
			for (int j = N; prime[j]; j++) 
				cnt++;
			cout << cnt << "\n";
		}
	}
	return 0;
}