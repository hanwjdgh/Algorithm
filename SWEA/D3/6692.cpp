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
		double p, sum = 0.0;
		int x;

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> p >> x;
			sum += (p*x);
		}
		cout << fixed;
		cout.precision(6);
		cout << "#" << t_case << " " << sum << "\n";
	}

	return 0;
}