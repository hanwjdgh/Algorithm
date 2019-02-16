#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int film[14][21], temp[14][21];
int D, W, K, min_v;
vector <int > ans;

void copy_arr() {
	for (int i = 0; i < D; i++)
		for (int j = 0; j < W; j++)
			temp[i][j] = film[i][j];
}

void find(int cnt, int cur, int num) {
	if (num >= min_v)
		return;
	if (cur == cnt) {
		copy_arr();

		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] == 0)
				continue;
			for (int j = 0; j < W; j++)
				temp[i][j] = ans[i];
		}

		bool err = false;
		for (int i = 0; i < W; i++) {
			int num = 1;
			for (int j = 0; j < D - 1; j++) {
				if (temp[j][i] == temp[j + 1][i])
					num++;
				else
					num = 1;
				if (num == K)
					break;
			}
			if (num != K) {
				err = true;
				break;
			}
		}

		if (!err)
			min_v = min(min_v, num);

		return;
	}

	for (int i = 0; i < 3; i++) {
		ans.push_back(i);
		if (i == 0)
			find(cnt + 1, cur, num);
		else
			find(cnt + 1, cur, num + 1);
		ans.pop_back();
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		memset(film, 0, sizeof(film));
		memset(temp, 0, sizeof(temp));
		cin >> D >> W >> K;

		min_v = D + 1;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> film[i][j];
				film[i][j] += 1;
			}
		}

		find(0, D, 0);

		cout << "#" << t_case << " " << min_v << "\n";
	}

	return 0;
}
