#include <iostream>
#include <ios>

#define MAX 10000000

using namespace std;

int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
int mat[4][4], cn;
int visit[MAX];

void find(int x, int y, int hap, int cnt) {
	if (cnt == 7) {
		if (!visit[hap]) {
			cn++;
			visit[hap] = 1;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
			continue;
		find(nx, ny, hap * 10 + mat[nx][ny], cnt + 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		cn = 0;
		fill(visit, visit + MAX, 0);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> mat[i][j];

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				find(i, j, mat[i][j], 1);

		cout << "#" << t_case << " " << cn << "\n";
	}

	return 0;

}