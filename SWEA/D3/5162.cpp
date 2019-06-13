#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int T, A, B, C;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int ans = 0;

		cin >> A >> B >> C;

		ans = max(ans, (C / A) + (C%A / B));
		ans = max(ans, (C / B) + (C%A / A));

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}