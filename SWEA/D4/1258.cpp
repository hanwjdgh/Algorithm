#include <iostream>
#include <ios>
#include <queue>

using namespace std;

struct submtx {
	int row, col, size;
};

bool operator<(submtx a, submtx b) {
	if (a.size > b.size)
		return true;
	else if (a.size == b.size) {
		if (a.row > b.row)
			return true;
	}

	return false;
}

priority_queue <submtx > pq;
int map[101][101];
int T, N, cnt;

void find(int cy, int cx) {
	int ycnt = 1, xcnt = 1;
	int ny = cy, nx = cx;

	while (1) {
		ny += 1;

		if (ny >= N || map[ny][cx] == 0)
			break;

		ycnt++;
	}

	while (1) {
		nx += 1;

		if (nx >= N || map[cy][nx] == 0)
			break;

		xcnt++;
	}

	for (int y = cy; y < ny; y++)
		for (int x = cx; x < nx; x++)
			map[y][x] = 0;

	pq.push({ ycnt, xcnt, ycnt*xcnt });
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		cnt = 0;

		cin >> N;

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> map[y][x];

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (!map[y][x])
					continue;

				cnt++;
				find(y, x);
			}
		}

		cout << "#" << t_case << " " <<  cnt << " ";

		while (!pq.empty()) {
			submtx temp = pq.top();
			pq.pop();

			cout << temp.row << " " << temp.col << " ";
		}

		cout << "\n";
	}

	return 0;
}