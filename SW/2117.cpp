#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

struct House {
	int y, x;
};

House house[401];
int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
int cost[22], city[21][21];
int N, M;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int i = 1; i <= 21; i++)
		cost[i] = i * i + (i - 1)*(i - 1);

	for (int t_case = 1; t_case <= T; t_case++) {
		int cnt = 0, K, idx = 0;
		cin >> N >> M;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> city[y][x];
				if (city[y][x] == 1)
					house[idx].y = y, house[idx++].x = x;
			}
		}

		for (K = 21; K > -1; K--)
			if (cost[K] <= idx*M)
				break;

		while (K > 0) {
			cout << K << endl;
			int hcnt = 0;

			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					int chk = 0;

					for (int i = 0; i < idx; i++)
						if ((abs(y - house[i].y) + abs(x - house[i].x)) <= K - 1)
							chk++;
					if (cost[K] <= chk*M)
						hcnt = max(hcnt, chk);
				}
			}
			cnt = max(cnt, hcnt);
			K--;
		}

		cout << "#" << t_case << " " << cnt << "\n";
	}

	return 0;
}
