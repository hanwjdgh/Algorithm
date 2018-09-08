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
	int L;

	cin >> L >> P;

	for (int i = 1, j = 0; i < L; i++) {
		while (j > 0 && P[i] != P[j])
			j = fail[j - 1];
		if (P[i] == P[j])
			fail[i] = ++j;
	}

	if (fail[L - 1] > 0)
		cout << L - fail[L - 1] << "\n";
	else
		cout << L << "\n";
	return 0;
}