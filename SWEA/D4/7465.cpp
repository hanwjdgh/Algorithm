#include <iostream>
#include <ios>

using namespace std;

int T, ans, N, M;
int par[101], visit[101];

int find(int a) {
	if (a == par[a])
		return a;
	else
		return par[a] = find(par[a]);
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

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int a, b;

		ans = 0;


		cin >> N >> M;

		for (int i = 1; i <= N; i++)
			par[i] = i;

		for (int i = 0; i < M; i++) {
			cin >> a >> b;

			merge(a, b);
		}

		for (int i = 1; i <= N; i++) {
			if (visit[find(par[i])])
				continue;
			visit[find(par[i])] = 1;
			ans++;
		}

		cout << "#" << t_case << " " << ans << "\n";

		for (int i = 0; i <= N; i++)
			visit[i] = 0;
	}

	return 0;
}