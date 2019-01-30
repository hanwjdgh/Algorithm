#include <iostream>
#include <cstdio>
#include <vector>
#include <limits>

using namespace std;

typedef pair <int, int> p;

int main() {
	int T, N, M, W;

	cin >> T;
	while (T--) {
		int dis[501];
		vector <p > v[501];
		int a, b, c, chk = 0;

		cin >> N >> M >> W;
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			v[a].push_back(make_pair(b, c));
			v[b].push_back(make_pair(a, c));
		}
		for (int i = 0; i < W; i++) {
			cin >> a >> b >> c;
			v[a].push_back(make_pair(b, -c));
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
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}