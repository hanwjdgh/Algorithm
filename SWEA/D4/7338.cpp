#include <iostream>
#include <ios>

using namespace std;

int T, N;
long long year, mon;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		cin >> year >> mon;

		cout << "#" << t_case << " ";
		if (year == 2016)
			cout << year << " " << mon << "\n";
		else {
			long long ytmp = 2016 + ((year - 2016) * 12 + mon) / 13;
			long long mtmp = ((year - 2016) * 12 + mon) % 13;
			
			if (mtmp == 0)
				ytmp--, mtmp = 13;
			
			cout << ytmp << " " << mtmp << "\n";
		}

	}

	return 0;
}