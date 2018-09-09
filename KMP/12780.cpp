#include <iostream>
#include <ios>
#include <string>

#define MAX 100001

using namespace std;

int fail[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string H, N;
	int n, m, cnt=0;

	cin >> H >> N;
	n = H.length();
	m = N.length();

	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && N[i] != N[j])
			j = fail[j - 1];
		if (N[i] == N[j])
			fail[i] = ++j;
	}
	
	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && H[i] != N[j])
			j = fail[j - 1];
		if (H[i] == N[j]) {
			if (j == m - 1) {
				cnt++;
				j = fail[j];
			}
			else
				j++;
		}
	}
	cout << cnt << "\n";
	return 0;
}