#include <iostream>
#include <ios>
#include <string>

#define MOD 1000000007

using namespace std;

int T;
long long ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 1;
		string str;

		cin >> str;

		if (str.length() != 1) {
			for (int i = 0; i < str.length(); i++) {
				if (i == 0)
					ans *= (str[i] != str[i + 1]) ? 2 : 1;

				else if (i == str.length() - 1)
					ans *= (str[i] != str[i - 1]) ? 2 : 1;

				else {
					int cnt = 0;
					if (str[i - 1] != str[i])
						cnt++;
					if (str[i] != str[i + 1])
						cnt++;
					if (str[i - 1] != str[i + 1])
						cnt++;

					if (str[i - 1] == str[i] && str[i] == str[i + 1] && str[i - 1] == str[i + 1])
						cnt = 1;

					ans *= cnt;
				}

				ans %= MOD;
			}
		}
		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}