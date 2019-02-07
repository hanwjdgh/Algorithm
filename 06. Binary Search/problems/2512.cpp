#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int max_v;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector <int > v;
	int N, M, num;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
		max_v = max(max_v, num);
	}

	cin >> M;

	int L = 0, R = max_v;

	while (L <= R) {
		int mid = (L + R) / 2;
		long long sum = 0;

		for (auto next : v) {
			if (next < mid)
				sum += next;
			else
				sum += mid;
		}

		if (sum > M)
			R = mid - 1;
		else
			L = mid + 1;
	}

	cout << L - 1 << "\n";

	return 0;
}