#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;

	cin >> N;

	for (int i = N; i > -1; i--) {
		bool error = false;
		int temp = i;

		while (temp > 0) {
			if (temp % 10 != 4 && temp % 10 != 7) {
				error = true;
				break;
			}
			temp /= 10;
		}

		if (!error) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}