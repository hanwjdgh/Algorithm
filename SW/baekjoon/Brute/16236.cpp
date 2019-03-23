#include <iostream>
#include <ios>
#include <queue>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple <int, int, int > t;

int arr[21][21], visit[21][21];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int sx, sy, s_size = 2, eat_num;
int N;

vector <t > v;

void find() {
	queue <t> q;
	visit[sx][sy] = 1;
	q.push({ 0,sx,sy });

	while (!q.empty()) {
		int dis = get<0>(q.front()), cx = get<1>(q.front()), cy = get<2>(q.front());
		q.pop();

		if (arr[cx][cy] != 0 && arr[cx][cy] < s_size)
			v.push_back({ dis,cx,cy });

		for (int i = 0; i < 4; i++) {
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if (nx < 0 || ny<0 || nx >= N || ny >= N || visit[nx][ny] || arr[nx][ny] > s_size || visit[nx][ny])
				continue;
			visit[nx][ny] = 1;
			q.push({ dis + 1,nx,ny });
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int ans = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				sx = i, sy = j;
				arr[i][j] = 0;
			}
		}
	}

	while (1) {
		memset(visit, 0, sizeof(visit));
		v.clear();

		find();
		if (v.size() == 0)
			break;

		sort(v.begin(), v.end());
		
		ans += get<0>(v[0]);
		sx = get<1>(v[0]), sy = get<2>(v[0]);

		arr[sx][sy] = 0;
		eat_num++;
		if (eat_num == s_size) {
			s_size++;
			eat_num = 0;
		}
	}

	cout << ans << "\n";

	return 0;
}