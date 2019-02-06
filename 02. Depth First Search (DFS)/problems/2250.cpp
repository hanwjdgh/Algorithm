#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

#define MAX 10001

using namespace std;

vector <vector <int > > v;
int rot[MAX];
int min_v[MAX], max_v[MAX];
int height, cnt = 1;

void dfs(int cur, int level) {
	if (cur == -1)
		return;

	height = max(height, level);

	for (int i = 0; i < 2; i++) {
		dfs(v[cur][i], level + 1);
		if (i == 0) {		
			max_v[level] = max(max_v[level], cnt);
			min_v[level] = min(min_v[level], cnt);
			cnt++;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, a, b, c, st;
	int width = 0, lvl = 0;

	cin >> N;

	v.resize(N + 1);
	fill(min_v, min_v + MAX, 10001);

	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		v[a].push_back(b);
		v[a].push_back(c);

		rot[a]++;
		if (b != -1) 
			rot[b]++;
		if (c != -1) 
			rot[c]++;

	}

	for (int i = 1; i <= N; i++) {
		if (rot[i] == 1) {
			st = i;
			break;
		}
	}

	dfs(st, 1);

	for (int i = 1; i <= height; i++) {
		int temp = max_v[i] - min_v[i] + 1;

		if (temp > width) {
			width = temp;
			lvl = i;
		}
	}

	cout << lvl << " " << width << "\n";

	return 0;
}