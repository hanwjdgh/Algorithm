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

	int N, K, cnt = 0;

	cin >> N >> K;

	prime[1] = true;
	for (int i = 2; i <= N; ++i) {
		if (prime[i])
			continue;
		cnt++;
		if (cnt == K) {
			cout << i << "\n";
			break;
		}
		for (int j = i * 2; j <= N; j += i) {
			if (prime[j])
				continue;
			cnt++;
			if (cnt == K) {
				cout << j << "\n";
				break;
			}
			prime[j] = true;
		}
	}
	return 0;
}