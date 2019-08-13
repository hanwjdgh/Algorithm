#include <iostream>
#include <ios>

using namespace std;

int T, ans, N, D;
int city[300001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int cnt;
		ans = 0;

		cin >> N >> D;

		cnt = D - 1;
		for (int i = 0; i < N; i++)
			cin >> city[i];

		for (int i = 0; i < N; i++) {
			if (cnt == 0 && city[i] == 0) {
				ans++;
				cnt = D - 1;
				continue;
			}

			if (city[i] == 1) {
				cnt = D - 1;
				continue;
			}
			cnt--;
		}

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}