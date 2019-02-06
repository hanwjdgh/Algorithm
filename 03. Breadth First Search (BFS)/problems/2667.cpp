#include <iostream>
#include <ios>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 26

using namespace std;

typedef pair <int, int > p;

int visit[MAX][MAX];
char area[MAX][MAX];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, cnt = 0, chk = 0;
	vector <int > v;

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> area[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			if (!visit[i][j] && area[i][j] == '1') {
				queue <p > q;
				chk++;
				cnt = 0;
				q.push({ i,j });
				visit[i][j] = 1;

				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					cnt++;

					for (int i = 0; i < 4; i++) {
						int nx = x + dir[i][0], ny = y + dir[i][1];
						if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny] || area[nx][ny] == '0')
							continue;
						q.push({ nx,ny });
						visit[nx][ny] = 1;
					}
				}
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << chk << "\n";
	for (auto n : v)
		cout << n << "\n";

	return 0;
}