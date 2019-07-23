#include <iostream>
#include <ios>
#include <tuple>
#include <queue>

#define MAX 22

using namespace std;

typedef tuple <int, int, int > t;

char arr[MAX][MAX];
int R, C, memory;
int dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
int visit[MAX][MAX][4][16];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		bool chk = false;
		queue <t > q;
		memory = 0;

		cin >> R >> C;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '@')
					chk = true;
			}
		}

		if (chk) {
			q.push(make_tuple(0, 0, 0));
			visit[0][0][0][memory] = 1;
		}
		chk = false;

		while (!q.empty()) {
			int x = get<0>(q.front()), y = get<1>(q.front()), d = get<2>(q.front());
			q.pop();

			if (arr[x][y] >= '0' && arr[x][y] <= '9') memory = arr[x][y] - '0';
			else if (arr[x][y] == '>') d = 0;
			else if (arr[x][y] == 'v') d = 1;
			else if (arr[x][y] == '<') d = 2;
			else if (arr[x][y] == '^') d = 3;
			else if (arr[x][y] == '_') d = (memory == 0) ? 0 : 2;
			else if (arr[x][y] == '|') d = (memory == 0) ? 1 : 3;
			else if (arr[x][y] == '+') memory = (memory + 1) % 16;
			else if (arr[x][y] == '-') memory = (memory + 15) % 16;
			else if (arr[x][y] == '@') {
				chk = true;
				break;
			}
			else if (arr[x][y] == '?') {
				for (int i = 0; i < 4; i++) {
					int nx = (x + dir[i][0] + R) % R, ny = (y + dir[i][1] + C) % C;
					if (visit[nx][ny][i][memory] == t_case)
						continue;
					visit[nx][ny][i][memory] = t_case;
					q.push(make_tuple(nx, ny, i));
				}
				continue;
			}
			int nx = (x + dir[d][0] + R) % R, ny = (y + dir[d][1] + C) % C;
			if (visit[nx][ny][d][memory] == t_case)
				continue;
			visit[nx][ny][d][memory] = t_case;
			q.push(make_tuple(nx, ny, d));
		}

		cout << "#" << t_case << " " << (chk ? "YES" : "NO") << "\n";
	}

	return 0;

}