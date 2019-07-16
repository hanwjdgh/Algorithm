#include <iostream>
#include <ios>
#include <cstring>

#define MAX 17

using namespace std;

int T;
char map[MAX][MAX];
int visit[MAX][MAX];
int max_v, ans;
int chk;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

void find(int x, int y) {
	visit[x][y] = 1;
	if (x == 13 && y == 13) {
		chk = 1;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (nx < 0 || ny < 0 || nx >= 16 || ny >= 16 || visit[nx][ny] || map[nx][ny] == '1')
			continue;
		find(nx, ny);
	}
}

int main() {
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	for (int test = 0; test < 10; test++) {
		chk = 0;
		memset(visit, 0, sizeof(visit));
		cin >> T;

		for (int i = 0; i < 16; i++) 
			for (int j = 0; j < 16; j++) 
				cin >> map[i][j];
		
		find(1, 1);
		if (chk)
			cout << "#" << test + 1 << " " << "1" << "\n";
		else
			cout << "#" << test + 1 << " " << "0" << "\n";

	}
	return 0;
}