#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int > arr;

int main() {
	int N, k;

	cin >> N >> k;

	int left = 1, right = k, ans;
	while (left <= right) {
		int mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 1; i <= N; i++)
			cnt += min(mid / i, N);
		if (cnt < k)
			left = mid + 1;
		else
			ans = mid, right = mid - 1;
	}
	cout << ans;
	return 0;
}