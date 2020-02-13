#include <iostream>
#include <ios>
#include <deque>
#include <algorithm>

using namespace std;

int T, L;
char bracket[1001];
int idx[1001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		deque <int > dq;

		cin >> L;

		for (int i = 0; i < L; i++)
			cin >> bracket[i];

		cout << "#" << t_case << " ";

		if (L % 2 == 1)
			cout << -1 << "\n";

		else {
			int cnt = 0, chk = 0;
			bool checkEmpty = false;

			for (int i = 0; i < L; i++) {
				if (bracket[i] == '(')
					dq.push_back(i);
				else {
					if (!dq.empty())
						dq.pop_back();
					else {
						chk++;
						idx[cnt++] = i;
					}
				}
			}

			checkEmpty = (!dq.empty()) ? false : true;

			while (!dq.empty()) {
				idx[cnt++] = dq.front();
				dq.pop_front();
			}
			if (chk == 0) {
				if (!checkEmpty)
					cout << 1 << "\n" << idx[cnt / 2] << " " << L - 1 << "\n";
				else
					cout << 0 << "\n";
			}

			else {
				if (!checkEmpty) {
					cout << 2 << "\n";
					cout << 0 << " " << idx[chk - 1] << "\n";

					int temp = idx[chk - 1];

					for (int i = 0; i < chk; i++) {
						int tmp = idx[chk - 1 - i];
						idx[chk - 1 - i] = temp - tmp;
					}

					for (int i = 0; i < chk / 2; i++)
						swap(idx[i], idx[chk - 1 - i]);

					cout << idx[cnt / 2] << " " << L - 1 << "\n";
				}
				else
					cout << 1 << "\n" << 0 << " " << idx[cnt / 2] << "\n";
			}
		}
	}

	return 0;
}