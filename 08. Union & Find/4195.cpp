#include <iostream>
#include <ios>
#include <map>
#include <string>

#define MAX 200002

using namespace std;

map <string, int > m;
int par[MAX], snum[MAX];

int find(int n) {
	if (n == par[n])
		return n;
	return par[n] = find(par[n]);
}

int merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		par[a] = b;
		snum[b] += snum[a];
		snum[a] = 1;
	}
	return snum[b];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T, F;

	cin >> T;

	while (T--) {
		string st1, st2;
		m.clear();


		cin >> F;
		for (int i = 1; i <= F * 2; i++) {
			par[i] = i;
			snum[i] = 1;
		}
		int cnt = 1;
		for (int i = 0; i < F; i++) {
			cin >> st1 >> st2;
			if (m[st1] == 0)
				m[st1] = cnt++;

			if (m[st2] == 0)
				m[st2] = cnt++;
			cout << merge(m[st1], m[st2]) << "\n";
		}
	}
	return 0;
}