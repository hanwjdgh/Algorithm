#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

struct Camera {
	int y, x;
};

Camera camera[65];
int visit[65];
int map[9][9], temp[9][9];
int N, M, min_v = 1e9, c_cnt;

void go(int cy, int cx, int dir) {
	int num = temp[cy][cx];

	switch (dir) {
	case 0:
		for (int i = cy; i > -1; i--) {
			if (temp[i][cx] == 6)
				break;
			else if (temp[i][cx] == 0)
				temp[i][cx] = num;
		}
		break;
	case 1:
		for (int i = cx; i < M; i++) {
			if (temp[cy][i] == 6)
				break;
			else if (temp[cy][i] == 0)
				temp[cy][i] = num;
		}
		break;
	case 2:
		for (int i = cy; i < N; i++) {
			if (temp[i][cx] == 6)
				break;
			else if (temp[i][cx] == 0)
				temp[i][cx] = num;
		}
		break;
	case 3:
		for (int i = cx; i > -1; i--) {
			if (temp[cy][i] == 6)
				break;
			else if (temp[cy][i] == 0)
				temp[cy][i] = num;
		}
		break;
	default:
		break;
	}
}

void find(int cnt) {
	if (cnt == c_cnt) {

		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				temp[y][x] = map[y][x];
		
		for (int i = 0; i < c_cnt; i++) {
			int cy = camera[i].y, cx = camera[i].x;
			int cd = visit[i];
			int c_cum = temp[cy][cx];
		
			switch (c_cum) {
			case 1:
				go(cy, cx, cd);
				break;
			case 2:
				if (cd % 2 == 0) {
					go(cy, cx, 0);
					go(cy, cx, 2);
				}
				else {
					go(cy, cx, 1);
					go(cy, cx, 3);
				}
				break;
			case 3:
				go(cy, cx, cd);
				go(cy, cx, (cd + 1) % 4);
				break;
			case 4:
				for (int j = 0; j < 4; j++) {
					if ((cd + 3) % 4 == j)
						continue;
					go(cy, cx, j);
				}
				break;
			case 5:
				for (int j = 0; j < 4; j++)
					go(cy, cx, j);
				break;
			default:
				break;
			}
		}

		int val = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++)
				if (temp[y][x] == 0)
					val++;
		}
		min_v = min(min_v, val);

		return;
	}

	for (int i = 0; i < 4; i++) {
		visit[cnt] = i;
		find(cnt + 1);
		visit[cnt] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			if (map[y][x] >= 1 && map[y][x] <= 5) {
				camera[c_cnt].y = y, camera[c_cnt].x = x;
				c_cnt++;
			}
		}
	}

	if (c_cnt == 0) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)
					cnt++;
			}
		}
		min_v = cnt;
	}
	else 
		find(0);

	cout << min_v << "\n";

	return 0;
}