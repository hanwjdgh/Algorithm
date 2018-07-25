#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N;
int pan[21][21] = { 0, };

int slice(int sx, int sy, int fx, int fy, char dir) {
	if (sx == fx || sy == fy) 
		return 0;

	vector <int > x, y;
	int bo = 0, bul = 0;
	for (int i = sx; i < fx; i++) {
		for (int j = sy; j < fy; j++) {
			if (pan[i][j] == 2)
				bo++;
			else if (pan[i][j] == 1) {
				x.push_back(i);
				y.push_back(j);
				bul++;
			}
		}
	}
	if (bo == 0) 
		return 0;
	if (bo == 1 && bul == 0)
		return 1;
	if (bo > 2 && bul == 0)
		return 0;

	int ret = 0;
	if (dir != 'c') {
		for (int idy : y) {
			int chk = 0;
			for (int i = sx; i < fx; i++) {
				if (pan[i][idy] == 2) {
					chk = 1;
					break;
				}
			}
			if(!chk)
				ret += (slice(sx, sy, fx, idy, 'c') * slice(sx, idy+1, fx, fy, 'c'));
		}
	}

	if (dir != 'r') {
		for (int idx : x) {
			int chk = 0;
			for (int i = sy; i < fy; i++) {
				if (pan[idx][i] == 2) {
					chk = 1;
					break;
				}
			}
			if (!chk)
				ret += (slice(sx, sy, idx, fy, 'r') * slice(idx+1, sy, fx, fy, 'r'));
		}
	}
	return ret;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			scanf("%d", &pan[i][j]);
	
	int ans = slice(0, 0, N, N, '0');
	printf("%d\n",(ans == 0 ? -1 : ans));
	return 0;
}