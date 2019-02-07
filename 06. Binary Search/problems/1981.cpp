#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define MAX 101

using namespace std;

typedef pair <int, int > p;

int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
int arr[MAX][MAX];
int visit[MAX][MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int L = 0, R = 0;
	int min_v = 201, max_v = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			min_v = min(min_v, arr[i][j]);
			max_v = max(max_v, arr[i][j]);
		}
	}
	
	R = max_v - min_v;
	while (L <= R) {
		int mid = (L + R) / 2;
		int chk = 0;

		for (int i = min_v; i <= max_v; i++) {
			memset(visit, 0, sizeof(visit));

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (arr[j][k] < i || arr[j][k] > i + mid)
						visit[j][k] = 1;
				}
			}

			if (visit[0][0])
				continue;

			queue <p > q;

			q.push({ 0,0 });
			visit[0][0] = 1;

			while (!q.empty()) {
				int cx = q.front().first, cy = q.front().second;
				q.pop();

				if (cx == n - 1 && cy == n - 1) {
					chk = 1;
					break;
				}

				for (int i = 0; i < 4; i++) {
					int nx = cx + dir[i][0], ny = cy + dir[i][1];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n || visit[nx][ny])
						continue;
					q.push({ nx,ny });
					visit[nx][ny] = 1;
				}
			}
			if (chk)
				break;
		}

		if (chk)
			R = mid - 1;
		else
			L = mid + 1;
	}

	cout << L << "\n";

	return 0;
}