#include <iostream>
#include <ios>

using namespace std;

int T;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int ans = 0, N;
		int num[10] = { 0, };

		cin >> N;

		while (N > 0) {
			if (!num[N % 10]) {
				num[N % 10]++, ans++;
			}
			N /= 10;

		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}