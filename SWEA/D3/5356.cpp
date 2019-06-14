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
		string str[5];
		int max_v = 0;

		for (int i = 0; i < 5; i++) {
			cin >> str[i];
			
			if (max_v < str[i].length())
				max_v = str[i].length();
		}

		cout << "#" << t_case << " ";

		for (int i = 0; i < max_v; i++) {
			for (int j = 0; j < 5; j++) {
				if (str[j].length() - 1 < i)
					continue;
				cout << str[j][i];
			}
		}

		cout << "\n";

	}

	return 0;
}