#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int num[10001];
int T, N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int ans = 0, sum = 0;

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> num[i];
			sum += num[i];
		}

		sum /= N;

		for (int i = 0; i < N; i++) {
			if (num[i] - sum > 0)
				ans += (num[i] - sum);
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}