#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int day[8] = { 3, 4, 5, 6, 0, 1, 2, 0 };
int mon[12] = { 0, 31,29,31,30,31,30,31,31,30,31,30 };
int T, m, d;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int ans = 0;

		cin >> m >> d;

		for (int i = 1; i < m; i++)
			ans += mon[i];

		ans += d;

		cout << "#" << t_case << " " << day[ans % 7] << "\n";
	}

	return 0;
}