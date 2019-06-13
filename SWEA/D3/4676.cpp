#include <iostream>
#include <ios>
#include <string>

using namespace std;

int T, Hcnt;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		string str;
		int cnt[21] = { 0, };
		int ans = 0, temp;

		cin >> str >> Hcnt;

		for (int i = 0; i < Hcnt; i++) {
			cin >> temp;
			cnt[temp]++;
		}

		cout << "#" << t_case << " ";

		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < cnt[i]; j++)
				cout << "-";
			if (i == str.length())
				break;
			cout << str[i];
		}

		cout << "\n";
	}

	return 0;
}