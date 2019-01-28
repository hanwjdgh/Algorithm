#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		long long x, k;

		cin >> x >> k;
		
		cout << 9 * (x - 1) + k << "\n";
	}

	return 0;
}