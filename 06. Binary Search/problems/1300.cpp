#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, k;

	cin >> N >> k;

	int L = 1, R = k;

	while (L <= R) {
		int mid = (L + R) / 2;
		long long cnt = 0;

		for (int i = 1; i <= N; i++)
			cnt += min(mid / i, N);
		if (cnt >= k)
			R = mid - 1;
		else
			L = mid + 1;
	}

	cout << L << "\n";

	return 0;
}