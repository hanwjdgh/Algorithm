#include <iostream>
#include <ios>
#include <cstring>

#define MAX 101

using namespace std;

int T;
char map[MAX][MAX];
int visit[MAX][MAX];
int max_v, ans;
int chk;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

void find(int x, int y) {
	visit[x][y] = 1;
	if (map[x][y]=='3') {
		chk = 1;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (nx < 0 || ny < 0 || nx >= 100 || ny >= 100 || visit[nx][ny] || map[nx][ny] == '1')
			continue;
		find(nx, ny);
	}
}

int main() {
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	for (int test = 0; test < 10; test++) {
		int x, y;
		chk = 0;
		memset(visit, 0, sizeof(visit));
		cin >> T;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
				if (map[i][j] == '2') {
					x=i,y=j;
				}
			}
		}
		find(x, y);
		if (chk)
			cout << "#" << test + 1 << " " << "1" << "\n";
		else
			cout << "#" << test + 1 << " " << "0" << "\n";

	}
	return 0;
}