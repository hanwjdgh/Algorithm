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
	int L = 0, R = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
		L = max(L, num);
		R += num;
	}


	while (L <= R) {
		int mid = (L + R) / 2;
		int sum = 0, cnt = 0;

		for (int i = 0; i < N; i++) {
			if (sum + v[i] > mid) {
				cnt++;
				sum = 0;
			}
			sum += v[i];
		}
		if (sum != 0)
			cnt++;

		if (cnt <= M)
			R = mid - 1;
		else
			L = mid + 1;
	}

	cout << L << "\n";

	return 0;
}