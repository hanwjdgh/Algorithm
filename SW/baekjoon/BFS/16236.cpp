#include <iostream>
#include <ios>
#include <queue>

using namespace std;

struct Shark {
	int y, x, dis;
};

bool operator<(Shark a, Shark b) {
	if (a.dis > b.dis)
		return true;
	else if (a.dis == b.dis) {
		if (a.y > b.y)
			return true;
		else if (a.y == b.y) {
			if (a.x > b.x)
				return true;
		}
	}
	return false;
}

Shark shark;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int map[21][21];
int N, s_size = 2, eat_cnt, ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 9) {
				shark.y = y, shark.x = x;
				map[y][x] = 0;
			}
		}
	}

	while (1) {
		int visit[21][21] = { 0, };

		priority_queue <Shark > pq;
		queue <Shark > q;
		shark.dis = 0;
		visit[shark.y][shark.x] = 1;
		q.push(shark);

		while (!q.empty()) {
			Shark cur = q.front();
			q.pop();

			if (map[cur.y][cur.x] != 0 && map[cur.y][cur.x] < s_size)
				pq.push(cur);

			for (int i = 0; i < 4; i++) {
				Shark next;
				next.y = cur.y + dir[i][0], next.x = cur.x + dir[i][1];
				next.dis = cur.dis + 1;

				if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= N || visit[next.y][next.x] || map[next.y][next.x] > s_size)
					continue;

				visit[next.y][next.x] = 1;
				q.push(next);
			}
		}

		if (pq.size() == 0)
			break;

		shark = pq.top();

		ans += shark.dis;
		map[shark.y][shark.x] = 0;

		eat_cnt++;

		if (eat_cnt == s_size) {
			s_size++;
			eat_cnt = 0;
		}
	}

	cout << ans << "\n";

	return 0;
}