#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

typedef struct Node {
	int y, x;
};

Node people[2501], chiken[2501];
int visit[2501];
int map[51][51];
int N, M, min_v = 1e9;
int p_cnt, c_cnt;

void dfs(int cur, int cnt) {
	if (cnt == M) {
		int min_total = 0;
		for (int i = 0; i < p_cnt; i++) {
			int min_dis = 1e9;
			for (int j = 0; j < c_cnt; j++) {
				if (!visit[j])
					continue;
				min_dis = min(min_dis, abs(people[i].y - chiken[j].y) + abs(people[i].x - chiken[j].x));
			}		
			min_total += min_dis;
		}
		min_v = min(min_v, min_total);

		return;
	}

	for (int i = cur; i < c_cnt; i++) {
		visit[i] = 1;
		dfs(i + 1,cnt+1);
		visit[i] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];

			if (map[y][x] == 1) {
				people[p_cnt].y = y, people[p_cnt].x = x;
				p_cnt++;
			}
			else if (map[y][x] == 2) {
				chiken[c_cnt].y = y, chiken[c_cnt].x = x;
				c_cnt++;
			}
		}
	}

	dfs(0,0);

	cout << min_v << "\n";

	return 0;
}