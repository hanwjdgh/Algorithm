#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B, V;

	cin >> A >> B >> V;

	int L = 1, R = (V / (A - B));

	while (L <= R) {
		int mid = (L + R) / 2;
		long long cnt = mid*(A - B) + A;
		if (cnt >= V)
			R = mid - 1;
		else
			L = mid + 1;
	}

	cout << L + 1 << "\n";

	return 0;
}