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
		int alpha[26] = { 0, }, ans = 0;
		string str;

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> str;

			alpha[str[0] - 'A']++;
		}

		for (int i = 0; i < 26; i++) {
			if (!alpha[i])
				break;
			ans++;
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}