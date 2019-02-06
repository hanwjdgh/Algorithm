#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int chk = 0, num = 0;

	cin >> N;

	for (int i = 1; i < N; i++) {
		int temp = i, sum = 0;
		sum += i;

		while (temp != 0) {
			sum += temp % 10;
			temp /= 10;
		}

		if (sum == N) {
			num = i;
			chk = 1;
			break;
		}
	}

	if (chk)
		cout << num << "\n";
	else
		cout << "0" << "\n";

	return 0;
}