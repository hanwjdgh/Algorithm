#include <iostream>
#include <ios>

using namespace std;

int T, ans;
long long N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int check = 0;
		long long t = 1, mul = 1;

		ans = 0;

		cin >> N;

		while (t < N) {
			if (!check)
				mul *= 4;
			t += mul;
			check = !check;
		}

		cout << "#" << t_case << " ";
		if (check)
			cout << "Alice" << "\n";
		else
			cout << "Bob" << "\n";
	}

	return 0;
}