#include <iostream>
#include <ios>
#include <queue>
#include <cstring>

#define MAX 101

using namespace std;

typedef pair <int, int> p;
queue <p > q;

char map[MAX][MAX] = { 0, };
int visit[MAX][MAX] = { 0, };
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M;
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	q.push({ 0,0 });
	visit[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == '1' && visit[nx][ny]==0) {
				visit[nx][ny] = visit[x][y] + 1;
				map[nx][ny] = '0';
				q.push({ nx,ny });
			}
		}
	}
	cout << visit[N - 1][M - 1];
	return 0;
}