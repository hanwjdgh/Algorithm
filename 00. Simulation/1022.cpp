#include <iostream>
#include <ios>
#include <cstdio>

using namespace std;

int map[50][5];
int dir[4][2] = { {0,1}, { -1,0 }, {0,-1}, { 1,0 } };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int r1, c1, r2, c2;
	int num = 1, x = 0, y = 0, cnt = 0;
	int di = 0, dnum = 1;

	cin >> r1 >> c1 >> r2 >> c2;

	while (!((map[0][0] != 0) && (map[r2 - r1][0] != 0) && (map[0][c2 - c1] != 0) && (map[r2 - r1][c2 - c1] != 0))) {

		if (x - r1 >= 0 && x - r1 <= (r2 - r1) && y - c1 >= 0 && y - c1 <= (c2 - c1)) 
			map[x - r1][y - c1] = num;

		num++;
		cnt++;

		x += dir[di][0];
		y += dir[di][1];

		if (cnt == dnum) {
			cnt = 0;

			di = (di + 1) % 4;
			if (di == 0 || di == 2)
				dnum++;
		}
	}

	cnt = 0;

	while (num > 0) {
		num /= 10;
		cnt++; 
	}


	for (int i = 0; i <= (r2 - r1); i++) {
		for (int j = 0; j <= (c2 - c1); j++)
			printf("%*d ", cnt, map[i][j]);
		printf("\n");
	}

	return 0;
}