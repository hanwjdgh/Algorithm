#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y, z, a, b, c;

	cin >> x >> y >> z;
	cin >> a >> b >> c;

	if (a >= x) {
		a -= x;
		int temp = a + b;
		if (temp >= y) {
			temp -= y;
			if (temp + c >= z)
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
		else
			cout << "NO" << "\n";
	}
	else
		cout << "NO" << "\n";

	return 0;
}