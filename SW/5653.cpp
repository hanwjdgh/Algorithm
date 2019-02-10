#include <iostream>
#include <ios>
#include <cstring>
#include <queue>
#include <tuple>
#include <algorithm>
#include <functional>

#define MAX 1002

using namespace std;

typedef pair <int, int > p;
typedef tuple <int, int, int > t;

vector <t > v;
int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
int N, M, K;
int cell[MAX][MAX], pr[MAX][MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		memset(cell, 0, sizeof(cell));
		memset(pr, 0, sizeof(pr));
		queue <t > q;
		v.clear();

		cin >> N >> M >> K;

		for (int i = 301; i < 301 + N; i++) {
			for (int j = 301; j < 301 + M; j++) {
				cin >> cell[i][j];
				if (cell[i][j] != 0)
					v.push_back(make_tuple(cell[i][j], i, j));
			}
		}

		sort(v.begin(), v.end(), greater<t >());

		for (auto n : v)
			q.push(n);

		for (int i = 0; i < K; i++) {
			int s = q.size();
			for (int j = 0; j < s; j++) {
				int t = get<0>(q.front()), x = get<1>(q.front()), y = get<2>(q.front());
				q.pop();

				pr[x][y]++;
				if (t + 1 == pr[x][y]) {
					for (int i = 0; i < 4; i++) {
						int nx = x + dir[i][0], ny = y + dir[i][1];
						if (pr[nx][ny] != 0 || cell[nx][ny] != 0)
							continue;
						cell[nx][ny] = t;
						q.push(make_tuple(cell[nx][ny], nx, ny));

					}
				}

				if (pr[x][y] == cell[x][y] * 2) {
					cell[x][y] = -1;
					continue;
				}

				q.push(make_tuple(t, x, y));
			}
		}

		int cnt = 0;

		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				if (cell[i][j] > 0)
					cnt++;

		cout << "#" << t_case << " " << cnt << "\n";
	}

	return 0;
}