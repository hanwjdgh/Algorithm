#include <iostream>
#include <ios>

using namespace std;

int mp[101][101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, L, ans = 0;

	cin >> N >> L;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> mp[i][j];

	for (int i = 0; i < N; i++) {
		int cnt = 1, tcnt = 1;
		bool check = false, tcheck = false;

		for (int j = 0; j < N - 1; j++) {
			if (mp[i][j] == mp[i][j + 1])
				cnt++;
			else if (mp[i][j] + 1 == mp[i][j + 1] && cnt >= L)
				cnt = 1;
			else if (mp[i][j] - 1 == mp[i][j + 1] && cnt >= 0)
				cnt = -L + 1;
			else
				break;

			if (j == N - 2)
				check = true;
		}
		if (cnt >= 0 && check)
			ans++;

		for (int j = 0; j < N - 1; j++) {
			if (mp[j][i] == mp[j + 1][i])
				tcnt++;
			else if (mp[j][i] + 1 == mp[j + 1][i] && tcnt >= L)
				tcnt = 1;
			else if (mp[j][i] - 1 == mp[j + 1][i] && tcnt >= 0)
				tcnt = -L + 1;
			else
				break;

			if (j == N - 2)
				tcheck = true;
		}
		if (tcnt >= 0 && tcheck)
			ans++;
	}

	cout << ans << "\n";

	return 0;
}