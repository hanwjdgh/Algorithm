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
	int N, C, num;

	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int L = 0, R = v[N - 1] - v[0];

	while (L <= R) {
		int mid = (L + R) / 2;
		int cnt = 1, temp = v[0];

		for (int i = 0; i < N - 1; i++) {
			if (v[i + 1] - temp >= mid) {
				cnt++;
				temp = v[i + 1];
			}
		}
		if (cnt < C)
			R = mid - 1;
		else
			L = mid + 1;
	}

	cout << L - 1<< "\n";

	return 0;
}