#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int q, a, b, c, d;

	cin >> q;

	for (int i = 0; i < q; i++) {
		int l, r, chk = 0;

		cin >> a >> b >> c >> d;
		
		for (int j = a; j <= b; j++) {
			l = j;
			for (int k = c; k <= d; k++) {
				if (k == l)
					continue;
				else {
					cout << l << " " << k << "\n";
					chk = 1;
					break;
				}
			}
			if (chk)
				break;
		}
	}

	return 0;
}