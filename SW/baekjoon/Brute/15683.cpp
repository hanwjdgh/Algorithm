#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair <int, int > p;

vector <p > v;
vector <int > ans;
int mp[9][9], temp[9][9];
int N, M, min_v = 1e9, c_cnt;


void copy_arr() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			temp[i][j] = mp[i][j];
}

int count_zero() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			if (temp[i][j] == 0)
				cnt++;
	}
	return cnt;
}

void go(int x, int y, int dir) {
	int num = temp[x][y];

	switch (dir){
	case 0:
		for (int i = x; i > -1; i--) {
			if (temp[i][y] == 6)
				break;
			else if (temp[i][y] == 0)
				temp[i][y] = num;
		}
		break;
	case 1:
		for (int i = y; i < M; i++) {
			if (temp[x][i] == 6)
				break;
			else if (temp[x][i] == 0)
				temp[x][i] = num;
		}
		break;
	case 2:
		for (int i = x; i < N; i++) {
			if (temp[i][y] == 6)
				break;
			else if (temp[i][y] == 0)
				temp[i][y] = num;
		}
		break;
	case 3:
		for (int i = y; i > -1; i--) {
			if (temp[x][i] == 6)
				break;
			else if (temp[x][i] == 0)
				temp[x][i] = num;
		}
		break;
	default:
		break;
	}
}

void find(int cnt) {
	if (cnt == c_cnt) {
		copy_arr();

		for (int i = 0; i < c_cnt; i++) {
			int c_cum = temp[v[i].first][v[i].second];
			switch (c_cum) {
			case 1:
				go(v[i].first, v[i].second, ans[i]);
				break;
			case 2:
				if (ans[i] % 2 == 0) {
					go(v[i].first, v[i].second, 0);
					go(v[i].first, v[i].second, 2);
				}
				else {
					go(v[i].first, v[i].second, 1);
					go(v[i].first, v[i].second, 3);
				}
				break;
			case 3:
				go(v[i].first, v[i].second, ans[i]);
				go(v[i].first, v[i].second, (ans[i] + 1) % 4);
				break;
			case 4:
				for (int j = 0; j < 4; j++) {
					if ((ans[i] + 3) % 4 == j)
						continue;
					go(v[i].first, v[i].second, j);
				}
				break;
			case 5:
				for (int j = 0; j < 4; j++)
					go(v[i].first, v[i].second, j);
				break;
			default:
				break;
			}
		}

		min_v = min(min_v, count_zero());

		return;
	}

	for (int i = 0; i < 4; i++) {
		ans.push_back(i);
		find(cnt + 1);
		ans.pop_back();
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mp[i][j];
			if (mp[i][j] >= 1 && mp[i][j] <= 5)
				v.push_back({ i,j });
		}
	}

	if (v.size() == 0) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (mp[i][j] == 0)
					cnt++;
			}
		}
		min_v = cnt;
	}
	else {
		c_cnt = v.size();
		find(0);
	}

	cout << min_v << "\n";

	return 0;
}