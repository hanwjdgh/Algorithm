#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int visit[21], f[11], s[11];
int ab[21][21];
int N, fidx, sidx, min_v = 1e9;

void dfs(int cnt) {
	if (cnt == N) {
		int sum_t1 = 0, sum_t2 = 0;
		if (fidx == sidx) {
			for (int i = 0; i < fidx; i++)
				for (int j = i + 1; j < fidx; j++)
					sum_t1 += (ab[f[i]][f[j]] + ab[f[j]][f[i]]);


			for (int i = 0; i < sidx; i++)
				for (int j = i + 1; j < sidx; j++)
					sum_t2 += (ab[s[i]][s[j]] + ab[s[j]][s[i]]);

			min_v = min(min_v, abs(sum_t1 - sum_t2));
		}
		return;
	}

	f[fidx++] = cnt;
	dfs(cnt + 1);
	fidx--;

	s[sidx++] = cnt;
	dfs(cnt + 1);
	sidx--;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> ab[y][x];

	dfs(0);

	cout << min_v << "\n";

	return 0;
}