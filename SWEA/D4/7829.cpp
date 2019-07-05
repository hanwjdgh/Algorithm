#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int T, P, ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;
		int num, max_v = 0, min_v = 1e9;

		cin >> P;

		for (int i = 0; i < P; i++) {
			cin >> num;
			max_v = max(max_v, num);
			min_v = min(min_v, num);
		}

		cout << "#" << t_case << " " << max_v * min_v << "\n";
	}

	return 0;
}