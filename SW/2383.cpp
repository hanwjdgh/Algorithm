#include <iostream>
#include <ios>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 11

using namespace std;

typedef pair <int, int > p;

vector <p > peo, st;
vector <int > ans, fs, ss;
int bang[MAX][MAX];
int N, min_v = 1e9, pcnt;

void down() {
	int cnt = 0, idx = 0, iidx = 0;
	int fx = st[0].first, fy = st[0].second;
	int sx = st[1].first, sy = st[1].second;
	queue <p > wfq, fdq;
	queue <p > wsq, sdq;

	while (1) {
		int a = wfq.size(), b = fdq.size(), c = wsq.size(), d = sdq.size();
		for (int i = idx; i < fs.size(); i++) {
			if (fs[i] == cnt) {
				wfq.push({ i,0 });
				idx++;
			}
		}

		for (int i = iidx; i < ss.size(); i++) {
			if (ss[i] == cnt) {
				wsq.push({ i,0 });
				iidx++;
			}
		}

		for (int i = 0; i < a; i++) {
			int cur = wfq.front().first, wait = wfq.front().second;
			wfq.pop();

			if (wait == 0 || fdq.size() >= 3) {
				wfq.push({ cur,1 });
				continue;
			}
			fdq.push({ cur,1 });
		}

		for (int i = 0; i < c; i++) {
			int cur = wsq.front().first, wait = wsq.front().second;
			wsq.pop();

			if (wait == 0 || sdq.size() >= 3) {
				wsq.push({ cur,1 });
				continue;
			}
			sdq.push({ cur,1 });
		}

		for (int i = 0; i < b; i++) {
			int cur = fdq.front().first, wait = fdq.front().second;
			fdq.pop();

			if (wait + 1 != bang[fx][fy])
				fdq.push({ cur,wait + 1 });
		}

		for (int i = 0; i < d; i++) {
			int cur = sdq.front().first, wait = sdq.front().second;
			sdq.pop();

			if (wait + 1 != bang[sx][sy])
				sdq.push({ cur,wait + 1 });
		}
		if (fdq.size() == 0 && wfq.size() == 0 && idx == fs.size() && sdq.size() == 0 && wsq.size() == 0 && iidx == ss.size())
			break;
		cnt++;
	}
	min_v = min(min_v, cnt);
}

void find(int cur) {
	if (cur == pcnt) {
		fs.clear();
		ss.clear();

		for (int i = 0; i < pcnt; i++) {
			if (ans[i] == 0)
				fs.push_back(abs(peo[i].first - st[0].first) + abs(peo[i].second - st[0].second));
			else
				ss.push_back(abs(peo[i].first - st[1].first) + abs(peo[i].second - st[1].second));
		}
		sort(fs.begin(), fs.end());
		sort(ss.begin(), ss.end());

		down();

		return;
	}

	for (int i = 0; i < 2; i++) {
		ans.push_back(i);
		find(cur + 1);
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
		ans.clear();
		peo.clear();
		memset(bang, 0, sizeof(bang));
		pcnt = 0, min_v = 1e9;
		st.clear();
		peo.clear();

		cin >> N;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> bang[i][j];
				if (bang[i][j] == 1) {
					pcnt++;
					peo.push_back({ i,j });
				}
				else if (bang[i][j] > 1)
					st.push_back({ i,j });
			}
		}

		find(0);

		cout << "#" << t_case << " " << min_v << "\n";
	}

	return 0;

}