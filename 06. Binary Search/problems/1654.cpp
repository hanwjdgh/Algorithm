#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector <long long > v;
	int K, N;
	long long num, max_v = 0, ans = 0;

	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> num;
		max_v = max(max_v, num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	long long L = 1, R = max_v;

	while (L <= R) {
		long long mid = (L + R) / 2;
		long long cnt = 0;

		for (int i = 0; i < K; i++)
			cnt += (v[i] / mid);

		if (cnt >= N) {
			ans = max(ans, mid);
			L = mid + 1;
		}
		else if (cnt < N)
			R = mid - 1;
	}

	cout << ans << "\n";

	return 0;
}