#include <iostream>
#include <ios>
#include <vector>

#define MAX 1001

using namespace std;

bool prime[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, num, cnt = 0;

	cin >> N;
	prime[1] = true;
	for (int i = 2; i <= MAX; ++i) {
		if (prime[i])
			continue;
		for (int j = i * 2; j <= MAX; j += i)
			prime[j] = true;
	}

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (!prime[num])
			cnt++;
	}
	cout << cnt << "\n";
	return 0;
}