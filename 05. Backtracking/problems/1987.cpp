#include <iostream>
#include <ios>
#include <string>
#include <algorithm>

using namespace std;

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int visit[21][21] = { 0, }, alpha[26] = { 0, };
int R, C, max_v = 0;
string board[21];

void backtrack(int x, int y, int cnt) {

	max_v = max(max_v, cnt);
	
	visit[x][y] = 1;
	alpha[board[x][y] - 'A'] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C || visit[nx][ny] == 1 || alpha[board[nx][ny] - 'A'] == 1)
			continue;
		backtrack(nx, ny, cnt + 1);
	}
	visit[x][y] = 0;
	alpha[board[x][y] - 'A'] = 0;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	cin >> R >> C;

	for (int i = 0; i < R; i++)
		cin >> board[i];

	backtrack(0, 0, 1);
	cout << max_v << endl;
	return 0;
}