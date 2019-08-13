#include <iostream>
#include <ios>

using namespace std;

int T, ans, N, K;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int hap[21] = { 0, }, cnt = 1;
		ans = 0;

		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) {
				for (int j = 0; j < K; j++) {
					hap[j] += cnt;
					cnt++;
				}
			}
			else {
				for (int j = K - 1; j > -1; j--) {
					hap[j] += cnt;
					cnt++;
				}
			}
		}

		cout << "#" << t_case << " ";

		for (int i = 0; i < K; i++)
			cout << hap[i] << " ";
		cout << "\n";

	}

	return 0;
}