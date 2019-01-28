#include <iostream>
#include <ios>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int q;

	cin >> q;

	for (int i = 0; i < q; i++) {
		int n;
		string str;

		cin >> n >> str;

		if (n == 1 || (n == 2 && str[0] >= str[1]))
			cout << "NO" << "\n";

		else {
			cout << "YES\n2" << "\n";
			cout << str[0] << " " << str.substr(1) << "\n";
		}

	}

	return 0;
}