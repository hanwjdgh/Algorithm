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

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		max_v = max(max_v, num);
		v.push_back(num);
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;
		max_v = max(max_v, num);
		t.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++) {
		int chk = 0;
		int L = 0, R = N - 1;

		while (L <= R) {
			int mid = (L + R) / 2;

			if (v[mid] < t[i])
				L = mid + 1;
			else if (v[mid] > t[i])
				R = mid - 1;
			else {
				chk = 1;
				break;
			}
		}
		if (chk)
			cout << "1" << "\n";
		else
			cout << "0" << "\n";
	}

	return 0;
}