#include <iostream>
#include <ios>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX 22

using namespace std;

typedef pair <int, int > p;

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int cost[MAX];
int city[MAX][MAX];
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
		vector <p > v;
		int cnt = 0, K;
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> city[i][j];
				if (city[i][j] == 1) {
					cnt++;
					v.push_back({ i,j });
				}
			}
		}

		for (K = 21; K > -1; K--)
			if (cost[K] <= cnt*M)
				break;

		cnt = 0;
		while (K > 0) {
			int hcnt = 0;

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int chk = 0;
					int cx = i, cy = j;
					for (int k = 0; k < v.size(); k++) {
						int nx = v[k].first, ny = v[k].second;

						if ((abs(cx - nx) + abs(cy - ny)) <= K - 1)
							chk++;
					}
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
