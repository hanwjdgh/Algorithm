#include <iostream>
#include <cstdio>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

typedef pair <int, long long> p;
vector <p > v[100];
queue <int > q;

int main() {
	int N, s, d, M;
	int a, b, chk = 0;
	long long c;
	long long dis[100], cost[100];
	int visit[100] = { 0, };

	cin >> N >> s >> d >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	}
	for (int i = 0; i < N; i++)
		cin >> cost[i];

	fill(dis, dis + N, numeric_limits<long long>::max());
	dis[s] = -cost[s];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < v[j].size(); k++) {
				int y = v[j][k].first;
				long long w = v[j][k].second - cost[y];
				if (dis[j] != numeric_limits<long long>::max() && dis[y] > dis[j] + w) {
					dis[y] = dis[j] + w;
					if (i == N - 1) {
						q.push(y);
						chk = 1;
					}
				}
			}
		}
	}
	if (chk == 1) {
		while (!q.empty()) {
			int val = q.front();
			q.pop();
			for (int i = 0; i < v[val].size(); i++) {
				int y = v[val][i].first;
				if (visit[y] == 1)
					continue;
				visit[y] = 1;
				q.push(y);
			}
		}
	}

	if (dis[d] == numeric_limits<long long>::max())
		printf("gg");
	else {
		if (chk == 1) {
			if (visit[d] == 1)
				printf("Gee");
			else
				printf("%d", -dis[d]);
		}
		else
			printf("%lld", -dis[d]);
	}

	return 0;
}