#include <iostream>
#include <ios>
#include <string>

using namespace std;

int T, B_len, S_len, ans;
int fail[100001];
string B, S;

void init() {
	ans = 0;

	for (int i = 0; i <= S_len; i++)
		fail[i] = 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {

		cin >> B >> S;

		B_len = B.length(), S_len = S.length();

		init();

		for (int i = 1, j = 0; i < S_len; i++) {
			while (j > 0 && S[i] != S[j])
				j = fail[j - 1];
			if (S[i] == S[j])
				fail[i] = ++j;
		}

		for (int i = 0, j = 0; i < B_len; i++) {
			while (j > 0 && B[i] != S[j])
				j = fail[j - 1];
			if (B[i] == S[j]) {
				if (j == S_len - 1) {
					ans++;
					j = fail[j];
				}
				else
					j++;
			}
		}

		cout << "#" << t_case << " " << ans << "\n";

	}
	return 0;
}