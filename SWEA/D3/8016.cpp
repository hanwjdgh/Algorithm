#include <iostream>
#include <ios>

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

		cout << "#" << t_case << " " << (2 * N*N - 4 * N + 3) << " " << (2 * N*N - 1) << "\n";

	}

	return 0;
}