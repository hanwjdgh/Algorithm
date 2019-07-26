#include <iostream>
#include <ios>

using namespace std;

int T, n, m, chk, a, b;
int par[1000001];
int ans[1000001];

int find(int n) {
	if (n == par[n])
		return n;
	return par[n] = find(par[n]);
}

void union1(int a, int b) {
	a = find(a);
	b = find(b);
	par[a] = b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int cnt = 0;

		cin >> n >> m;

		for (int i = 1; i <= n; i++)
			par[i] = i;

		for (int i = 0; i < m; i++) {
			cin >> chk >> a >> b;

			if (chk) {
				if (find(a) == find(b))
					ans[cnt++] = 1;
				else
					ans[cnt++] = 0;

			}
			else
				union1(a, b);
		}

		cout << "#" << t_case << " ";

		for (int i = 0; i < cnt; i++)
			cout << ans[i];

		cout << "\n";

	}

	return 0;
}