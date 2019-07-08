#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

typedef struct Node {
	int y, x;
}node;

node wnode[21];
int visit[21];
int T, N;
bool flag;
long long ans = 0;

void dfs(int idx, int cnt) {
	if (cnt == N / 2) {
		long long fy, fx, sy, sx;

		fy = fx = sy = sx = 0;

		for (int i = 0; i < N; i++) {
			if (visit[i])
				fy += wnode[i].y, fx += wnode[i].x;
			else
				sy += wnode[i].y, sx += wnode[i].x;
		}

		fy -= sy, fx -= sx;

		if (!flag) {
			flag = true;
			ans = (fy*fy) + (fx*fx);
		}
		else
			ans = min(ans, (fy*fy) + (fx*fx));

		return;
	}

	for (int i = idx; i < N; i++) {
		visit[i] = 1;
		dfs(i + 1, cnt + 1);
		visit[i] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		flag = false;

		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> wnode[i].y >> wnode[i].x;

		dfs(0, 0);

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}