#include <iostream>
#include <ios>
#include <string>
#include <queue>

using namespace std;

string S, temp[1001];
char alpha[10][4] = {
	{},{},
{'A','a','b','c'},
{ 'A','d','e','f' },
{ 'A','g','h','i' },
{ 'A','j','k','l' },
{ 'A','m','n','o' },
{ 'p','q','r','s' },
{ 'A','t','u','v' },
{ 'w','x','y','z' } };
int T, N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int ans = 0;
		queue <string > q;

		cin >> S >> N;

		for (int i = 0; i < N; i++) 
			cin >> temp[i];

		for (int i = 0; i < N; i++) {
			if (temp[i].length() != S.length())
				continue;

			int chk = false;
			for (int j = 0; j < S.length(); j++) {
				int idx = S[j] - '0';

				bool find = false;
				for (int k = 0; k < 4; k++) {
					if (alpha[idx][k] == 'A')
						continue;

					if (alpha[idx][k] == temp[i][j]) {
						find = true;
						break;
					}
				}
				if (!find) {
					chk = true;
					break;
				}
			}

			if (!chk)
				ans++;
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}