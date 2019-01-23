#include <iostream>
#include <ios>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;

	cin >> str;

	int r = 1, c = 1;

	for (auto n : str) {
		if (n == '0') {
			cout << r << " " << 1 << "\n";
			r += 2;
			if (r == 5)
				r = 1;
		}
		else {
			cout << c << " " << 2 << "\n";
			c += 1;
			if (c == 5)
				c = 1;
		}
	}

	return 0;
}