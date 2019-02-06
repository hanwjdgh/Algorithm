#include <iostream>
#include <ios>
#include <queue>
#include <cstring>

#define MAX 101

using namespace std;

typedef pair <int, int > p;

int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int visit[MAX][MAX];
char area[MAX][MAX];
int N;


int bfs() {
	int cnt = 0;
	char temp;
	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				queue <p > q;

				temp = area[i][j];
				cnt++;
				q.push({ i,j });
				visit[i][j] = 1;

				while (!q.empty()) {
					int cx = q.front().first, cy = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = cx + dir[k][0], ny = cy + dir[k][1];
						if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny] || area[nx][ny] != temp)
							continue;
						q.push({ nx,ny });
						visit[nx][ny] = 1;
					}

				}
			}
		}
	}
	
	return cnt;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int ans1 = 0, ans2 = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> area[i][j];

	ans1 = bfs();

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			area[i][j] = (area[i][j] == 'G') ? 'R' : area[i][j];

	ans2 = bfs();

	cout << ans1 << " " << ans2 << "\n";

	return 0;
}