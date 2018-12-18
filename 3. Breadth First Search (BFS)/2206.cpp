#include <iostream>
#include <ios>
#include <cstring>
#include <queue>
#include <tuple>
#include <algorithm>

#define MAX 1001

using namespace std;

typedef tuple <int, int, int > t;
queue <t > q;
int visit[MAX][MAX][2] = { 0, };
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, chk = 0;
	char wall[MAX][MAX];

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> wall[i];

	visit[0][0][1] = 1;
	q.push({ 0,0,1 });

	while (!q.empty()) {
		int x = get<0>(q.front()), y = get<1>(q.front()), can = get<2>(q.front());
		q.pop();
		if (x == N - 1 && y == M - 1) {
			chk = 1;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			if (visit[nx][ny][can] != 0)
				continue;

			if (wall[nx][ny] == '1' && can == 1) {
				visit[nx][ny][can - 1] = visit[x][y][can] + 1;
				q.push({ nx,ny,can - 1 });
			}
			else if (wall[nx][ny] == '0') {
				visit[nx][ny][can] = visit[x][y][can] + 1;
				q.push({ nx,ny,can });
			}
		}
	}
	if (chk == 1)
		cout << max(visit[N - 1][M - 1][0],visit[N - 1][M - 1][1]) << endl;
	else
		cout << "-1";
	return 0;
}