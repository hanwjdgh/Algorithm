#include <iostream>
#include <ios>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Contury {
	int y, x;
};

Contury con[10001];

int A[101][101];
int dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
int N, L, R, ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> L >> R;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> A[y][x];

	bool find = true;

	while (find) {
		find = false;

		int visit[101][101] = { 0, };

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (visit[y][x])
					continue;

				int cnt = 0, hap = 0;
				Contury temp;
				temp.y = y, temp.x = x;
				visit[y][x] = 1;
				queue <Contury > q;
				q.push(temp);

				while (!q.empty()) {
					Contury cur = q.front();
					int cur_v = A[cur.y][cur.x];
					q.pop();

					con[cnt++] = cur;
					hap += cur_v;

					for (int i = 0; i < 4; i++) {
						Contury next;
						next.y = cur.y + dir[i][0], next.x = cur.x + dir[i][1];
						int next_v = A[next.y][next.x];

						if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= N || visit[next.y][next.x])
							continue;
						if (abs(cur_v - next_v) < L || abs(cur_v - next_v) > R)
							continue;

						find = true;
						q.push(next);
						visit[next.y][next.x] = 1;
					}
				}

				for (int i = 0; i < cnt; i++)
					A[con[i].y][con[i].x] = hap / cnt;
			}
		}
		if (find)
			ans++;
	}

	cout << ans << "\n";

	return 0;
}