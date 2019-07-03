#include <iostream>
#include <ios>
#include <cmath>

using namespace std;

int T;
long long N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		cin >> N;

		long long temp = cbrt(N);

		if (pow(temp, 3) == N)
			cout << "#" << t_case << " " << temp << "\n";
		else if (pow(temp + 1, 3) == N)
			cout << "#" << t_case << " " << temp + 1 << "\n";
		else
			cout << "#" << t_case << " " << -1 << "\n";
	}

	return 0;
}