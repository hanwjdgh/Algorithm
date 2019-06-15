#include <iostream>
#include <ios>
#include <string>

using namespace std;

int T, N, M;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		string fstr[101], sstr[1001];
		int fchk[101] = { 0, }, schk[1001] = { 0, };
		int mon[101], ans = 0;

		cin >> N >> M;

		for (int i = 0; i < N; i++)
			cin >> fstr[i] >> mon[i];

		for (int i = 0; i < M; i++)
			cin >> sstr[i];

		for (int i = 0; i < N; i++) {
			if (fchk[i])
				continue;

			for (int j = 0; j < M; j++) {
				if (schk[j])
					continue;

				int k;
				for (k = 0; k < 8; k++) {
					if (fstr[i][k] != '*' && fstr[i][k] != sstr[j][k])
						break;
				}

				if (k == 8) {
					fchk[i] = schk[j] = 1;
					ans += mon[i];
				}
			}
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}