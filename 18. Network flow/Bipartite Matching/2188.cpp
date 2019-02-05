#include <iostream>
#include <cstdio>
#include <vector>

#define MAX 201

using namespace std;

int d[MAX];
bool c[MAX];
vector <int > adj[MAX];

bool dfs(int x) {
	for (int i = 0; i < adj[x].size(); i++) {
		int t = adj[x][i];
		if (c[t])
			continue;
		c[t] = true;
		if (d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main() {
	int N, M, si, num;
	int count = 0;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> si;
		for (int j = 0; j < si; j++) {
			cin >> num;
			adj[i].push_back(num);
		}
	}
	for (int i = 1; i <= N; i++) {
		fill(c, c + MAX, false);
		if (dfs(i))
			count++;
	}
	printf("%d\n", count);
	return 0;
}