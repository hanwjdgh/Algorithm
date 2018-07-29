#include <iostream>
#include <ios>
#include <queue>
#include <algorithm>

#define MAX 1001

using namespace std;

typedef pair <int, int > p;

queue <p > q;
int box[MAX][MAX] = { 0, }, visit[MAX][MAX] = { 0, };
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N, M, cnt=0,chk=0;
	int max_v = 1;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> box[i][j];
			if (box[i][j] == 0)
				cnt++;
			if (box[i][j] == 1) {
				q.push({ i,j });
				visit[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		int cx = q.front().first, cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
				continue;
			if (visit[nx][ny] != 0)
				continue;
			if (box[nx][ny] == -1)
				continue;
	
			visit[nx][ny] = visit[cx][cy]+1;
			max_v = max(max_v, visit[nx][ny]);
			box[nx][ny] = 1;
			q.push({ nx,ny });	
			chk++;
		}
	}
	if (cnt == chk || cnt == 0)
		cout << max_v - 1;
	else
		cout << "-1";
	return 0;
}