#include <iostream>
#include <ios>
#include <string>

using namespace std;

int T, N;
string X;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		long long ans = 0;

		cin >> N >> X;

		N--;

		for (int i = 0; i < X.length(); i++)
			ans += (X[i] - '0');

		cout << "#" << t_case << " " << ans%N << "\n";
	}

	return 0;
}