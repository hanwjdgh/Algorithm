#include <iostream>
#include <ios>

using namespace std;

int T, N, M;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int ans = 0, max_v = 0;
		int A[1001] = { 0, }, B[1001] = { 0, };
		int vote[1001] = { 0 , };

		cin >> N >> M;

		for (int i = 0; i < N; i++) 
			cin >> A[i];

		for (int i = 0; i < M; i++)
			cin >> B[i];

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (A[j] <= B[i]) {
					vote[j]++;
					break;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			if (max_v < vote[i]) {
				max_v = vote[i];
				ans = i + 1;
			}
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}