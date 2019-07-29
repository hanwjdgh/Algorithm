#include <iostream>
#include <ios>
#include <string>
#include <cstring>

using namespace std;

int T, p, q;
string str;
bool dp[21][21][21];
int ans[11];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		memset(dp, true, sizeof(dp));
		int s = 0, m = 0, l = 0;
		for (int i = 0; i < 11; i++)
			ans[i] = -2;

		cin >> p >> q;

		for (int i = 0; i < p; i++) {
			cin >> str;

			int cnt = 0;

			for (int j = 0; j < str.length(); j++) {
				if (str[j] == '.')
					cnt++;
				else
					break;
			}

			for (int a = 1; a < 21; a++) {
				for (int j = 1; j < 21; j++) {
					for (int k = 1; k < 21; k++) {
						if (a*s + j*m + k*l != cnt)
							dp[a][j][k] = false;
					}
				}
			}


			for (int j = cnt; j < str.length(); j++) {
				if (str[j] == '(') ++s;
				else if (str[j] == ')') --s;
				else if (str[j] == '{') ++m;
				else if (str[j] == '}') --m;
				else if (str[j] == '[') ++l;
				else if (str[j] == ']') --l;
			}
		}

	

		s = 0, m = 0, l = 0;

		for (int i = 0; i < q; i++) {
			cin >> str;

			for (int a = 1; a < 21; a++) {
				for (int j = 1; j < 21; j++) {
					for (int k = 1; k < 21; k++) {
						if (!dp[a][j][k])
							continue;
						int val = a*s + j*m + k*l;

						if (ans[i] == -2)
							ans[i] = val;
						else if (ans[i] >= 0 && ans[i] != val)
							ans[i] = -1;
					}
				}
			}


			for (int j = 0; j < str.length(); j++) {
				if (str[j] == '(') ++s;
				else if (str[j] == ')') --s;
				else if (str[j] == '{') ++m;
				else if (str[j] == '}') --m;
				else if (str[j] == '[') ++l;
				else if (str[j] == ']') --l;
			}
		}

		cout << "#" << t_case << " ";

		for (int i = 0; i < q; i++)
			cout << ans[i] << " ";

		cout << "\n";

	}

	return 0;
}