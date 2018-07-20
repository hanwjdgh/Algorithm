#include <iostream>
#include <cstdio>
#include <vector>
#include <limits>

using namespace std;

typedef pair <int, int> p;
vector <p > v[501];

int main() {
	int N, M;
	int a, b, c, chk = 0;
	int dis[501];

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	}
	fill(dis, dis + N + 1, numeric_limits<int >::max());
	dis[1] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < v[j].size(); k++) {
				int y = v[j][k].first;
				int w = v[j][k].second;
				if (dis[j] != numeric_limits<int >::max() && dis[y] > dis[j] + w) {
					dis[y] = dis[j] + w;
					if (i == N)
						chk = 1;
				}
			}
		}
	}
	if (chk == 1)
		printf("-1\n");
	else {
		for (int i = 2; i <= N; i++)
			printf("%d\n", dis[i] != numeric_limits<int >::max() ? dis[i] : -1);
	}
	return 0;
}