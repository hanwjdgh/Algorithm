#include <iostream>
#include <ios>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair <int, int >  p;

int N, M;
int map[51][51];
int visit[14];
int min_v = 1e9;

vector <p > ch, per;

void dfs(int cnt, int val) {
	if (cnt > ch.size())
		return;

	if (val == M) {
		int temp = 0;
		for (int i = 0; i < per.size(); i++) {
			int dist = 1e9;
			for (int j = 0; j < ch.size(); j++) {
				if (visit[j]) {
					int px = per[i].first, py = per[i].second;
					int cx = ch[j].first, cy = ch[j].second;
					int dis = abs(px - cx) + abs(py - cy);
					dist = min(dist, dis);
				}
			}
			temp += dist;
		}
		min_v = min(min_v, temp);
		return;
	}

	visit[cnt] = 1;
	dfs(cnt + 1, val + 1);
	visit[cnt] = 0;
	dfs(cnt + 1, val);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				per.push_back({ i,j });
			else if (map[i][j] == 2)
				ch.push_back({ i,j });
		}
	}
	dfs(0, 0);
	cout << min_v << "\n";
	return 0;
}