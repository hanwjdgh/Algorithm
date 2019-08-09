#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

struct Node {
	int val, cnt;
};

bool operator<(Node a, Node b) {
	if (a.cnt < b.cnt)
		return true;
	else if (a.cnt == b.cnt) {
		if (a.val < b.val)
			return true;
	}

	return false;
}

Node node[101];
int r, c, k, ans, R, C, idx;
int arr[101][101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> r >> c >> k;

	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			cin >> arr[y][x];

	R = C = 3;

	while (1) {
		int temp[101][101] = { 0, };
	
		if (arr[r - 1][c - 1] == k || ans > 100)
			break;
		
		if (R >= C) {
			for (int y = 0; y < R; y++) {
				idx = 0;
				int cnt[101] = { 0, };

				for (int x = 0; x < C; x++) {
					if (arr[y][x] == 0)
						continue;
					cnt[arr[y][x]]++;
				}

				for (int i = 1; i <= 100; i++) {
					if (!cnt[i])
						continue;

					node[idx].val = i, node[idx++].cnt = cnt[i];
				}

				sort(node, node + idx);

				for (int i = 0; i < idx; i++) {
					if (idx > 49)
						break;
					temp[y][i * 2] = node[i].val, temp[y][i * 2 + 1] = node[i].cnt;
				}

				C = max(C, idx * 2);
				C = (C > 100) ? 100 : C;
			}

		}

		else {
			for (int x = 0; x < C; x++) {
				idx = 0;
				int cnt[101] = { 0, };

				for (int y = 0; y < R; y++) {
					if (arr[y][x] == 0)
						continue;
					cnt[arr[y][x]]++;
				}

				for (int i = 1; i <= 100; i++) {
					if (!cnt[i])
						continue;

					node[idx].val = i, node[idx++].cnt = cnt[i];
				}

				sort(node, node + idx);

				for (int i = 0; i < idx; i++) {
					if (idx > 49)
						break;
					temp[i * 2][x] = node[i].val, temp[i * 2 + 1][x] = node[i].cnt;
				}

				R = max(R, idx * 2);
				R = (R > 100) ? 100 : R;
			}
		}

		for (int y = 0; y < R; y++) 
			for (int x = 0; x < C; x++) 
				arr[y][x] = temp[y][x];
		
		ans++;
	}

	ans = (ans > 100) ? -1 : ans;

	cout << ans << "\n";

	return 0;
}