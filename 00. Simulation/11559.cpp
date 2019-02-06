#include <iostream>
#include <ios>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

typedef pair <int, int > p;

string puyo[12];
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int visit[12][6];
int cnt;
queue <p > q;

void find(int x, int y, char cur) {
	q.push({ x,y });
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6 || visit[nx][ny] != 0 || puyo[nx][ny] != cur)
			continue;
		cnt++;
		find(nx, ny, cur);
	}
}

void convert() {
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		puyo[x][y] = '.';
	}
}

void down() {
	for (int i = 10; i > -1; i--) {
		for (int j = 0; j < 6; j++) {
			if (puyo[i][j] == '.')
				continue;

			int a = i, b = j;
			for (int k = i + 1; k < 12; k++)
				if (puyo[k][j] == '.') {
					a = k, b = j;
				}
			swap(puyo[i][j], puyo[a][b]);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 12; i++)
		cin >> puyo[i];

	int chk, ans = 0;
	while (1) {
		chk = 0;
		memset(visit, 0, sizeof(visit));

		for (int i = 11; i > -1; i--) {
			for (int j = 0; j < 6; j++) {
				if (!visit[i][j] && puyo[i][j] != '.') {
					cnt = 1;
					find(i, j, puyo[i][j]);
					if (cnt >= 4) {
						chk = 1;
						convert();
					}
					else {
						queue <p > empty;
						swap(q, empty);
					}
				}
			}
		}

		if (!chk)
			break;
		else
			ans++;

		down();
	}

	cout << ans << "\n";
	
	return 0;
}