#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define MAX 402

using namespace std;

int c[MAX][MAX] = { 0, }, f[MAX][MAX] = { 0, }, d[MAX];
vector <int > adj[MAX];

int main() {
	int N, M, si, num;
	int count = 0;
	int s = 0, t = 401;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		adj[s].push_back(i);
		adj[i].push_back(s);
		c[s][i] = 1;
	}
	
	for (int i = 1; i <= N; i++) {
		cin >> si;
		for (int j = 0; j < si; j++) {
			cin >> num;
			adj[i].push_back(num+200);
			adj[num + 200].push_back(i);
			c[i][num + 200] = 1;
			adj[num + 200].push_back(t);
			adj[t].push_back(num+200);
			c[num+200][t] = 1;
		}
	}

	while (1) {
		fill(d, d + MAX, -1);
		queue <int > q;
		q.push(s);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < adj[x].size(); i++) {
				int y = adj[x][i];
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x;
					if (y == t)
						break;
				}
			}
		}
		if (d[t] == -1)
			break;
		for (int i = t; i != s; i = d[i]) {
			f[d[i]][i]++;
			f[i][d[i]]--;
		}
		count++;
	}
	cout << count;
	return 0;
}