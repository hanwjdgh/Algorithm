#include <iostream>
#include <ios>
#include <string>

using namespace std;

int T, N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int ans[5] = { 0, };
		string str;
		bool flag = false;
		int cnt = 0;

		cin >> N;

		while (cnt < N) {
			cin >> str;

			int len = str.length();

			if (str[len - 1] == '.' || str[len - 1] == '?' || str[len - 1] == '!') {
				flag = true;
				len--;
			}

			if (str[0] >= 'A' && str[0] <= 'Z') {
				ans[cnt]++;

				for (int i = 1; i < len; i++) {
					if (str[i] <'a' || str[i] >'z') {
						ans[cnt]--;
						break;
					}
				}
			}
			
			if (flag) {
				flag = false;
				cnt++;
			}

		}

		cout << "#" << t_case << " ";

		for (int i = 0; i < cnt; i++)
			cout << ans[i] << " ";

		cout << "\n";

	}

	return 0;
}