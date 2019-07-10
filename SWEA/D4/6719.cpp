#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

double M[201];
int T, N, K;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		double ans = 0.0;

		cin >> N >> K;

		for (int i = 0; i < N; i++)
			cin >> M[i];

		sort(M, M + N);

		for (int i = N - K; i < N; i++) 
			ans = (ans + M[i]) / 2;

		cout << fixed;
		cout.precision(6);
		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}