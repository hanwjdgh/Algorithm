#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

struct Node {
	int T, P;
};

Node node[16];
int N, max_v;

void dfs(int cnt, int hap) {
	if (cnt == N + 1) {
		max_v = max(max_v, hap);
		return;
	}

	if (cnt + node[cnt].T <= N + 1)
		dfs(cnt +node[cnt].T, hap + node[cnt].P);
	if (cnt + 1 <= N + 1)
		dfs(cnt + 1, hap);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> node[i].T >> node[i].P;

	dfs(1, 0);

	cout << max_v << "\n";

	return 0;
}