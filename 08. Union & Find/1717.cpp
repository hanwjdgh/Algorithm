#include <iostream>
#include <ios>

#define MAX 1000001

using namespace std;

int par[MAX];

int find(int n) {
	if (n == par[n])
		return n;
	else
		return par[n] = find(par[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	par[b] = a;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, x, a, b;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		par[i] = i;

	while (m--) {
		cin >> x >> a >> b;

		if (x) {
			if (find(a) == find(b))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
		else
			merge(a, b);
	}
	return 0;
}