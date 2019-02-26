#include <iostream>
#include <ios>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair <int, int > p;

vector <p > v;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int N, M, max_v;
int lab[9][9], temp[9][9];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 0)
				v.push_back({ i,j });
		}
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			for (int k = j + 1; k < v.size(); k++) {

				for (int a = 0; a < N; a++)
					for (int b = 0; b < M; b++)
						temp[a][b] = lab[a][b];

				temp[v[i].first][v[i].second] = 1;
				temp[v[j].first][v[j].second] = 1;
				temp[v[k].first][v[k].second] = 1;

				for (int a = 0; a < N; a++) {
					for (int b = 0; b < M; b++) {
						if (temp[a][b] != 2)
							continue;

						queue <p > q;
						q.push({ a,b });
						
						while (!q.empty()) {
							int cx = q.front().first, cy = q.front().second;
							q.pop();

							for (int c = 0; c < 4; c++) {
								int nx = cx + dir[c][0], ny = cy + dir[c][1];
								if (nx < 0 || ny < 0 || nx >= N || ny >= M)
									continue;
								if (temp[nx][ny] == 0) {
									q.push({ nx,ny });
									temp[nx][ny] = 2;
								}
							}
						}
					}
				}

				int cnt = 0;
				for (int a = 0; a < N; a++) 
					for (int b = 0; b < M; b++) 
						if (temp[a][b] == 0)
							cnt++;
			
				max_v = max(max_v, cnt);
			}
		}
	}

	cout << max_v << "\n";

	return 0;
}