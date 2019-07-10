#include <iostream>
#include <ios>
#include <algorithm>
#include <cstring>

#define MAX 51

using namespace std;

char flag[MAX][MAX];
int cnt[MAX][4];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		memset(cnt, 0, sizeof(cnt));
		memset(flag, '0', sizeof(flag));
		int N, M, min_v = 1e9;

		cin >> N >> M;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> flag[i][j];

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < 4; j++)
				cnt[i + 1][j] = cnt[i][j];

			for (int j = 0; j < M; j++) {
				cnt[i + 1][0] += (flag[i][j] != 'W');
				cnt[i + 1][1] += (flag[i][j] != 'B');
				cnt[i + 1][2] += (flag[i][j] != 'R');
			}
		}

		for (int i = 2; i <= N - 1; i++) {
			for (int j = i; j <= N - 1; j++) {
				int val = 0;
				val += ((cnt[i - 1][0] - cnt[0][0]) + (cnt[j][1] - cnt[i - 1][1]) + (cnt[N][2] - cnt[j][2]));
				min_v = min(min_v, val);
			}
		}


		cout << "#" << t_case << " " << min_v << "\n";
	}

	return 0;

}