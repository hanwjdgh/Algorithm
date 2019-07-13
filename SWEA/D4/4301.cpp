#include <iostream>
#include <ios>
#include <cstring>

using namespace std;

int T, ans, N, M;
int map[1001][1001];
int dir[2][2] = { {2,0},{0,2} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		memset(map, 0, sizeof(map));
		ans = 0;

		cin >> N >> M;
		
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (map[y][x])
					continue;
				for (int i = 0; i < 2; i++) {
					int ny = y + dir[i][0], nx = x + dir[i][1];

					if (ny >= N || nx >= M || map[ny][nx])
						continue;
					map[ny][nx] = 1;
				}
			}
		}
		

		for (int y = 0; y < N; y++) 
			for (int x = 0; x < M; x++) 
				if (!map[y][x])
					ans++;


		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}