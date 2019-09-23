#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int N, M, K, min_v = 1e9;
int A[101][101];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int cond[4] = { 1,2,3,0 };

struct Node {
	int r, c, s;
};

Node node[6];
int arr[6], visit[6];

void find(int cnt) {
	if (cnt == K) {
		int temp[101][101] = { 0, };

		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				temp[y][x] = A[y][x];

		for (int i = 0; i < K; i++) {
			int idx = arr[i];
			int cy = node[idx].r - 1, cx = node[idx].c - 1, cs = node[idx].s;

			for (int j = 0; j < cs; j++) {
				int ny = cy - (j + 1), nx = cx, d = 0;
				int val = temp[ny][nx];
				for (int k = 0; k < (8 * (j + 1)); ) {		

					ny += dir[d][0], nx += dir[d][1];
					if (ny < (cy - (j + 1)) || nx < (cx - (j + 1)) || ny > (cy + (j + 1)) || nx > (cx + (j + 1))) {
						ny -= dir[d][0], nx -= dir[d][1];
						d = cond[d];
						continue;
					}
					swap(val, temp[ny][nx]);
					k++;
				}
			}
		}


		for (int y = 0; y < N; y++) {
			int tmp = 0;
			for (int x = 0; x < M; x++)
				tmp += temp[y][x];
			min_v = min(min_v, tmp);
		}

		return;
	}

	for (int i = 0; i < K; i++) {
		if (visit[i])
			continue;
		visit[i] = 1;
		arr[cnt] = i;
		find(cnt + 1);
		visit[i] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++) 
			cin >> A[y][x];

	for (int i = 0; i < K; i++)
		cin >> node[i].r >> node[i].c >> node[i].s;

	find(0);

	cout << min_v << "\n";

	return 0;
}