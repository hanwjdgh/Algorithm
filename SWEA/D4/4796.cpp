#include <iostream>
#include <ios>

using namespace std;

int T, ans, N;
int h[50001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;
		int cnt = 0, chk = 0;

		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> h[i];

		for (int i = 1; i < N; i++) {
			if (chk == 0 && h[i - 1] < h[i])
				cnt++;
			else if (h[i - 1] > h[i]) {
				ans += cnt;
				chk = 1;
			}
			else if (chk == 1 && h[i - 1] < h[i]) {
				cnt = 1;
				chk = 0;
			}
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}