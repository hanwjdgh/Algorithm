#include <iostream>
#include <ios>

using namespace std;

int T, d, ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;

		cin >> d;

		if (d < 100) ans = 0;
		else if (d < 1000) ans = 1;
		else if (d < 10000) ans = 2;
		else if (d < 100000) ans = 3;
		else if (d < 1000000) ans = 4;
		else ans = 5;

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}