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
		int alpha[26] = { 0, }, ans = 0;
		string str;

		cin >> str;

		for (int i = 0; i < str.length(); i++)
			alpha[str[i] - 'a']++;

		for(int i=0; i<26; i++)
			ans += ((alpha[i] * (alpha[i] + 1)) / 2);

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}