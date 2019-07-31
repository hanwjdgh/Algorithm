#include <iostream>
#include <ios>
#include <cstring>

using namespace std;

int T, ans, p, q;
int num[100001];
int res[100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int idx = 0;
		memset(res, -1, sizeof(res));

		ans = 0;

		cin >> p >> q;

		cout << "#" << t_case << " " << p / q;

		if (p%q != 0) {
			cout << ".";

			res[p%q] = idx++;
			p = p % q * 10;

			while (1) {
				int mok = p / q;
				int na = p%q;


				num[idx++] = mok;

				if (na == 0) {
					for (int i = 1; i < idx; i++)
						cout << num[i];
					break;
				}

				if (res[na] != -1) {
					if (res[na] == 0)
						cout << "(";
					for (int i = 1; i < idx; i++) {
						if (i == res[na])
							cout << "(";
						cout << num[i];
					}
					cout << ")";
					break;
				}

				res[na] = idx;
				p = na * 10;
			}

		}

		cout << "\n";
	}

	return 0;
}