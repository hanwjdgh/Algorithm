#include <iostream>
#include <ios>
#include <string>

using namespace std;

int T;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		string str;
		int len = 0, ans = 0, hap = 0;

		cin >> str;

		len = str.length();

		hap += str[0] - '0';

		for (int i = 1; i < len; i++) {
			if (str[i] == '0')
				continue;

			if (hap < i) {
				ans += (i - hap);
				hap += (i - hap);
			}

			hap += str[i] - '0';

		}

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}