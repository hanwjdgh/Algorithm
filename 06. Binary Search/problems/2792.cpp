#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	vector <int > v;
	int N, M, num;
	int L = 1, R = 0;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;
		v.push_back(num);
		R = max(R, num);
	}

	while (L <= R) {
		int mid = (L + R) / 2;
		int cnt = 0;

		for (int i = 0; i < M; i++) {
			cnt += v[i] / mid;
			if (v[i] % mid != 0)
				cnt++;
		}
	
		if (cnt <= N)
			R = mid - 1;
		else
			L = mid + 1;
	}

	cout << L << "\n";

	return 0;
}