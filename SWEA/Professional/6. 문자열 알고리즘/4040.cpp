#include <iostream>
#include <ios>
#include <string>
#include <algorithm>

#define MAX_L 1000001

using namespace std;

int T, S_len, max_v;
int fail[MAX_L];
string S;

void init() {
	max_v = 0;

	for (int i = 0; i < S_len; i++)
		fail[i] = 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {

		cin >> S;

		S_len = S.length();

		init();

		for (int i = 1, j = 0; i < S_len; i++) {
			while (j > 0 && S[i] != S[j])
				j = fail[j - 1];
			if (S[i] == S[j])
				fail[i] = ++j;
		}

		for (int i = 0; i < S_len; i++)
			max_v = max(max_v, fail[i]);

		cout << "#" << t_case << " ";


		if (fail[S_len - 1] == 0 || (S_len % (S_len - max_v) != 0))
			cout << 1 << "\n";
		else
			cout << S_len / (S_len - max_v) << "\n";

	}
	return 0;
}