#include <iostream>
#include <ios>
#include <string>

#define MAX 1000001

using namespace std;

int fail[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string P;

	while (1) {
		int L;

		fill(fail, fail + MAX, 0);

		cin >> P;

		if (P == ".")
			break;

		L = P.length();

		for (int i = 1, j = 0; i < L; i++) {
			while (j > 0 && P[i] != P[j])
				j = fail[j - 1];
			if (P[i] == P[j])
				fail[i] = ++j;
		}

		if (fail[L - 1] == 0)
			cout << 1 << "\n";
		else
			cout << fail[L - 1] / (L - fail[L - 1]) + 1 << "\n";
	}
	return 0;
}