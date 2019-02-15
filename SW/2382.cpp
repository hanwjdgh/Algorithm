#include <iostream>
#include <ios>
#include <cstring>
#include <tuple>
#include <vector>

#define MAX 101

using namespace std;

typedef tuple <int, int, int, int > t;

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int N, M, K;
int visit[MAX][MAX][2];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		memset(visit, 0, sizeof(visit));
		int a, b, c, d;
		vector <t > v;

		cin >> N >> M >> K;
	
		for (int i = 0; i < K; i++) {
			cin >> a >> b >> c >> d;
			v.push_back({ make_tuple(a,b,c,d - 1) });
		}

		while (M--) {
			memset(visit, 0, sizeof(visit));
			for (int i = 0; i < K; i++) {
				int cx = get<0>(v[i]), cy = get<1>(v[i]);
				if (get<2>(v[i]) == 0)
					continue;

				int nx = cx + dir[get<3>(v[i])][0], ny = cy + dir[get<3>(v[i])][1];
				get<0>(v[i]) = nx, get<1>(v[i]) = ny;
				if (nx == 0 || ny == 0 || nx == N - 1 || ny == N - 1)
					get<3>(v[i]) = (5 - get<3>(v[i])) % 4, get<2>(v[i]) /= 2;

				if (visit[nx][ny][0] == 0) {
					visit[nx][ny][0] = get<2>(v[i]);
					visit[nx][ny][1] = i;
				}
				else {
					int idx = visit[nx][ny][1];
					get<2>(v[idx]) += get<2>(v[i]);

					if (visit[nx][ny][0] < get<2>(v[i])) {
						visit[nx][ny][0] = get<2>(v[i]);
						get<3>(v[idx]) = get<3>(v[i]);
					}
					get<2>(v[i]) = 0;
				}
			}

		}
		int ans = 0;
		for (int i = 0; i < K; i++) 
			ans += get<2>(v[i]);
		
		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}
