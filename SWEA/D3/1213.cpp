#include <iostream>
#include <ios>
#include <vector>
#include <string>

using namespace std;

int fail[1001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; t <= 10; t++) {
		vector <int > v;
		string P, T;
		int n, N, M;

		cin >> n;

		cin >> P >> T;

		fill(fail, fail + 1001, 0);

		N = T.length();
		M = P.length();

		for (int i = 1, j = 0; i<M; i++) {
			while (j > 0 && P[i] != P[j])
				j = fail[j - 1];
			if (P[i] == P[j])
				fail[i] = ++j;
		}

		for (int i = 0, j = 0; i < N; i++) {
			while (j > 0 && T[i] != P[j])
				j = fail[j - 1];
			if (T[i] == P[j]) {
				if (j == M - 1) {
					v.push_back(i - M + 2);
					j = fail[j];
				}
				else
					j++;
			}
		}

		cout << "#" << t << " " << v.size() << "\n";
	}

	return 0;
}