#include <iostream>
#include <ios>
#include <string>
#include <algorithm>

using namespace std;

int T, ans;
string ori, sub;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;

		cin >> ori >> sub;

		for (int i = 0; i < ori.length(); i++) {
			if (ori[i] == sub[0]) {
				for (int j = 1; j < sub.length(); j++) {
					if (ori[i + j] != sub[j])
						break;
					if (j == sub.length() - 1)
						i += sub.length() - 1;
				}
			}
			ans++;
		}

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}