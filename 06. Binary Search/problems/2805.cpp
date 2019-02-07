#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector <int > v, t;
	int N, M, num;
	int max_v = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num;
		max_v = max(max_v, num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int L = 0, R = max_v;

	while (L <= R) {
		int mid = (L + R) / 2;
		long long sum = 0;

		for (int i = 0; i < N; i++)
			sum += (v[i] > mid) ? (v[i] - mid) : 0;

		if (sum >= M)
			L = mid + 1;
		else
			R = mid - 1;
	}

	cout << L - 1 << "\n";

	return 0;
}