#include <iostream>
#include <ios>
#include <string>
#include <cstring>
#include <algorithm>

#define MAX 51

using namespace std;

typedef pair <int, int > p;

string board[MAX];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int dp[MAX][MAX], visit[MAX][MAX];
bool error = false;
int N, M, ans = -1;

int find(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M || board[x][y] == 'H')
		return 0;

	if (visit[x][y]) {
		error = true;
		return -1;
	}

	int &ret = dp[x][y];

	if (ret != -1)
		return ret;

	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int val = board[x][y] - '0';
		int nx = x + dir[i][0] * val, ny = y + dir[i][1] * val;
		ret = max(ret, find(nx, ny) + 1);
	}
	visit[x][y] = 0;

	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int ans = 0, cnt = 1;

	memset(dp, -1, sizeof(dp));
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> board[i];

	ans = find(0, 0);
	if (!error)
		cout << ans << "\n";
	else
		cout << "-1" << "\n";
	return 0;
}