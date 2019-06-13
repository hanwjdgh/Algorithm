#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int T, S, E, M;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int ans = 0, Sr = 0, Mr = 0;

		cin >> S >> E >> M;

		ans = Sr = Mr = E;

		while (true) {
			if (Sr == S && Mr == M)
				break;

			Sr += 24;
			if (Sr > 365)
				Sr %= 365;

			Mr += 24;
			if (Mr > 29)
				Mr %= 29;

			ans += 24;
		}


		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}