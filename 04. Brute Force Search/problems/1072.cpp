#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long X, Y, Z;
	long long a, b, N;

	cin >> X >> Y;

	Z = Y * 100 / X;

	if (Z >= 99)
		cout << "-1" << "\n";
	else {
		a = (X*Z) + X - (100 * Y);
		b = 99 - Z;
		N = a / b;

		if (N*b < a)
			N++;

		cout << N << "\n";
	}

	return 0;
}