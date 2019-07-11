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
		int ans = 0, cnt = 0;
		char temp;
		string str;

		cin >> str;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') {
				cnt++;
				temp = '(';
			}
			else {
				cnt--;
				if (temp == '(')
					ans += cnt;
				else
					ans += 1;
				temp = ')';
			}
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}