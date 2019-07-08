#include <iostream>
#include <ios>
#include <cstring>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX 301

using namespace std;

typedef pair <int, int > p;

int dir[8][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 },{-1,-1},{-1,1},{1,-1},{1,1} };
int visit[MAX][MAX], mp[MAX][MAX];
char pan[MAX][MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int N, cnt = 0;
		memset(visit, 0, sizeof(visit));
		memset(mp, 0, sizeof(mp));
		memset(pan, '0', sizeof(pan));
		vector <p > v;
		cin >> N;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> pan[i][j];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (pan[i][j] == '.') {
					int chk = 0;
					for (int k = 0; k < 8; k++) {
						int nx = i + dir[k][0], ny = j + dir[k][1];
						if (nx < 0 || ny < 0 || nx >= N || ny >= N)
							continue;
						if (pan[nx][ny] == '*')
							chk++;
					}
					mp[i][j] = chk;
					if (chk == 0)
						v.push_back({ i,j });
				}
			}
		}

		for (int i = 0; i < v.size(); i++) {
			if (visit[v[i].first][v[i].second])
				continue;
			queue <p > q;
			q.push({ v[i].first,v[i].second });
			cnt++;

			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();

				pan[x][y] = mp[x][y] + '0';
				if (mp[x][y] == 0) {
					for (int k = 0; k < 8; k++) {
						int nx = x + dir[k][0], ny = y + dir[k][1];
						if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny])
							continue;
						q.push({ nx,ny });
						visit[nx][ny] = 1;
					}
				}
			}

		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (pan[i][j] == '.')
					cnt++;

		cout << "#" << t_case << " " << cnt << "\n";
	}

	return 0;

}