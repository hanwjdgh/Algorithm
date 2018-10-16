#include <iostream>
#include <ios>
#include <string>
#include <vector>

#define MAX 51

using namespace std;

int dir[6][2] = { { -1,-1 },{ -1,1 },{ 0,-1 },{ 0,1 },{ 1,-1 },{ 1,1 } };
int idx[11][11], d[MAX];
bool visit[MAX];
int N, M;

vector <vector<int > > adj;

bool dfs(int cur) {
	for (auto next : adj[cur]) {
		if (visit[next])
			continue;
		visit[next] = true;
		if (d[next] == -1 || dfs(d[next])) {
			d[next] = cur;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	while (T--) {
		int cnt = 0, b_idx = 0, chk = 0;
		fill(visit, visit + MAX, false);

		string board[11];
		vector <int > v;

		cin >> N >> M;

		for (int i = 0; i < N; i++)
			cin >> board[i];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < board[i].length(); j++) {
				if (board[i][j] == 'x')
					cnt++;

				if (j % 2 == 0)
					v.push_back(b_idx / 2);
				idx[i][j] = b_idx++ / 2;
			}
		}

		adj.clear();
		adj.resize(MAX);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 'x' || j % 2 == 1)
					continue;

				for (int a = 0; a < 6; a++) {
					int nx = i + dir[a][0];
					int ny = j + dir[a][1];

					if (nx < 0 || ny < 0 || nx >= N || ny >= M || board[nx][ny] == 'x')
						continue;
					adj[idx[i][j]].push_back(idx[nx][ny]);
				}
			}
		}
		fill(d, d + MAX, -1);
		for (auto a : v) {
			fill(visit, visit+MAX, false);
			if (dfs(a))
				chk++;
		}
		cout << N*M - chk - cnt << "\n";
	}
	return 0;
}