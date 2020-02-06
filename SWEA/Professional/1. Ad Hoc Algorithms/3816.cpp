#include <iostream>
#include <ios>
#include <string>

using namespace std;

int T;
int S1_Alpha[26], S2_Alpha[26];
string S1, S2;

bool check() {

	for (int i = 0; i < 26; i++) {
		if (S1_Alpha[i] != S2_Alpha[i])
			return false;
	}
	return true;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		
		for (int i = 0; i < 26; i++)
			S1_Alpha[i] = S2_Alpha[i] = 0;

		int ans = 0;

		cin >> S1 >> S2;

		int S1_Len = S1.length(), S2_Len = S2.length();

		for (int i = 0; i < S1_Len; i++) {
			S1_Alpha[S1[i] - 'a']++;
			S2_Alpha[S2[i] - 'a']++;
		}

		if (check())
			ans++;

		for (int i = 1; i < (S2_Len - S1_Len + 1); i++) {
			S2_Alpha[S2[i - 1] - 'a']--;
			S2_Alpha[S2[i + S1_Len - 1] - 'a']++;

			if (check())
				ans++;
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}