#include <iostream>
#include <ios>
#include <algorithm>
#include <queue>

using namespace std;

struct People {
	int y, x, st, dis, w_time, r_time;
};

struct Stair {
	int y, x, len;
};

bool operator<(People a, People b) {
	if (a.r_time > b.r_time)
		return true;
	else if (a.r_time == b.r_time) {
		if (a.dis > b.dis)
			return true;
	}
	return false;
}

People people[11];
Stair stair[2];
int p_cnt, st_cnt, min_v = 1e9;
int N, map[11][11], visit[11];

void dfs(int cur) {
	if (cur == p_cnt) {
		priority_queue <People > pq;

		for (int i = 0; i < cur; i++) {
			people[i].st = visit[i];
			people[i].dis = abs(people[i].y - stair[visit[i]].y) + abs(people[i].x - stair[visit[i]].x);
			pq.push(people[i]);
		}

		int val = 0;
		int wait[2] = { 0, };
		while (!pq.empty()) {
			People cur_peo = pq.top();
			pq.pop();

			val = cur_peo.r_time;
			cur_peo.r_time += 1;

			if (cur_peo.dis >= val) {
				pq.push(cur_peo);
				continue;
			}

			if (cur_peo.w_time != 0) {
				if (cur_peo.w_time == stair[cur_peo.st].len) {
					wait[cur_peo.st]--;
					continue;
				}
				cur_peo.w_time += 1;
				pq.push(cur_peo);
				continue;
			}

			if (wait[cur_peo.st] == 3) {
				pq.push(cur_peo);
			}
			else {
				wait[cur_peo.st]++;
				cur_peo.w_time += 1;
				pq.push(cur_peo);
			}
		}

		min_v = min(min_v, val);
		return;
	}

	for (int i = 0; i < 2; i++) {
		visit[cur] = i;
		dfs(cur + 1);
		visit[cur] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		p_cnt = st_cnt = 0;
		min_v = 1e9;
		cin >> N;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> map[y][x];
				if (map[y][x] == 1) {
					people[p_cnt].y = y, people[p_cnt++].x = x;
					people[p_cnt].st = people[p_cnt].w_time = people[p_cnt].dis = people[p_cnt].r_time = 0;
				}
				else if (map[y][x] > 1)
					stair[st_cnt].y = y, stair[st_cnt].x = x, stair[st_cnt++].len = map[y][x];
			}
		}

		dfs(0);

		cout << "#" << t_case << " " << min_v << "\n";
	}

	return 0;
}