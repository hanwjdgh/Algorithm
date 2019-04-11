#include <iostream>
#include <ios>

using namespace std;

int ladder[31][11];
int N, M, H, target;
bool not_err;

void dfs(int idx, int cnt) {
	if (not_err)
		return;

	if (cnt == target) {
		for (int i = 1; i <= N; i++) {
			int temp = i;
			for (int j = 1; j <= H; j++) {
				if (ladder[j][temp])
					temp++;
				else if (temp - 1 > 0 && ladder[j][temp - 1] == 1)
					temp--;
			}
			if (temp == i) {
				not_err = true;
				continue;
			}
			else {
				not_err = false;
				break;
			}
		}

		return;
	}

	for (int i = idx; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (ladder[i][j])
				continue;
			if (ladder[i][j - 1] != 1 && ladder[i][j + 1] != 1) {
				ladder[i][j] = 1;
				dfs(i, cnt + 1);
				ladder[i][j] = 0;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;

	cin >> N >> M >> H;

	while (M--) {
		cin >> a >> b;
		ladder[a][b] = 1;
	}

	for (int i = 0; i < 4; i++) {
		target = i;
		dfs(1, 0);
		if (not_err)
			break;
	}

	if (not_err)
		cout << target << "\n";
	else
		cout << "-1" << "\n";

	return 0;
}