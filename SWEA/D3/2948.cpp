#include <iostream>
#include <ios>
#include <algorithm>
#include <string>

using namespace std;

string far[100001], sar[100001];
int T, N, M;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int ans = 0;

		cin >> N >> M;

		for (int i = 0; i < N; i++)
			cin >> far[i];

		for (int i = 0; i < M; i++)
			cin >> sar[i];

		sort(far, far + N);
		sort(sar, sar + M);

		for (int i = 0; i < N; i++) {
			int L = 0, R = M;

			while (L <= R) {
				int mid = (L + R) / 2;

				if (sar[mid] > far[i])
					R = mid - 1;
				else if (sar[mid] == far[i]) {
					ans++;
					break;
				}
				else
					L = mid + 1;
			}
		}

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}