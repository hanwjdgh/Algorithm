#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int num[1001];
int T, N, max_v;

void dfs(int idx, int cnt, int val) {
	if (cnt == 2) {
		bool err = false;

		int temp = val % 10, tmp = val / 10;

		while (tmp > 0) {
			if (tmp % 10 > temp) {
				err = true;
				break;
			}

			temp = tmp % 10;
			tmp /= 10;
		}

		if (!err)
			max_v = max(max_v, val);

		return;
	}

	for (int i = idx; i < N; i++) {
		dfs(i + 1, cnt + 1, val*num[i]);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		cin >> N;

		max_v = -1;

		for (int i = 0; i < N; i++)
			cin >> num[i];

		dfs(0, 0, 1);

		cout << "#" << t_case << " " << max_v << "\n";
	}

	return 0;
}