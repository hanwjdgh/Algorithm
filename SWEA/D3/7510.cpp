#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int T, N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int ans = 1, val = 2, sum = 1;

		cin >> N;

		while (1) {
			int temp = N;

			sum += val;
			temp -= sum;

			if (temp < 0)
				break;

			if (temp%val == 0)
				ans++;

			val++;
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}