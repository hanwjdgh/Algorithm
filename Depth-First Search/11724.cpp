#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int > v[1001];
int visit[1001] = { 0, };

void dfs(int n) {
	visit[n] = 1;
	for (int i = 0; i < v[n].size(); i++) {
		int y = v[n][i];
		if (!visit[y])
			dfs(y);
	}
}

int main() {
	int N, M;
	int a, b, cnt = 0;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			cnt++;
			dfs(i);
		}
	}
	printf("%d\n", cnt);
	return 0;
}