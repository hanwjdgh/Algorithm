#include <iostream>
#include <ios>
#include <algorithm>
#include <string>

using namespace std;

int T;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		string str;

		cin >> str;

		cout << "#" << t_case << " ";

		if ((str[str.length() - 1] - '0') % 2 == 0)
			cout << "Even" << "\n";
		else
			cout << "Odd" << "\n";
	}

	return 0;
}