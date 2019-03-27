#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Node {
	int y, x;
};

vector <Node > temp;
Node people[2501], chiken[2501];
int map[51][51];
int N, M, min_v = 1e9;
int p_cnt, c_cnt;

void dfs(int cur) {
	if (temp.size() == M) {
		int min_total = 0;
		for (int i = 0; i < p_cnt; i++) {
			int min_dis = 1e9;
			for (auto n : temp) 
				min_dis = min(min_dis, abs(people[i].y - n.y) + abs(people[i].x - n.x));
			min_total += min_dis;
		}
		min_v = min(min_v, min_total);

		return;
	}

	for (int i = cur; i < c_cnt; i++) {
		temp.push_back(chiken[i]);
		dfs(i + 1);
		temp.pop_back();
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

	dfs(0);

	cout << min_v << "\n";

	return 0;
}