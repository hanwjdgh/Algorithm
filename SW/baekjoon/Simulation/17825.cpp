#include <iostream>
#include <ios>
#include <algorithm>
#include <cstring>

using namespace std;

struct Hores {
	int loc, line, d, state;
};

Hores hor[5];
int num[11], hores[11], ans;
int play[3][21] = { {},{ 10,13,16,19,25,26,27,28,30 },{ 20,22,24,25,30,35,40 } };
int visit[3][21];

void calNode(int idx, int val) {
	int pre = hor[idx].loc;

	if (hor[idx].line == 0) {
		int next = pre + val;

		if (next == 5 || next == 10 || next == 15) {
			hor[idx].line = ((next / 5) % 2 == 1) ? 1 : 2;
			hor[idx].loc = (next < 15) ? 0 : 8;
			hor[idx].d = (next < 15) ? 0 : 1;
		}

		else
			hor[idx].loc = next;

		if (next > 20) {
			visit[0][pre] = hor[idx].loc = 0;
			hor[idx].state = -1;
		}
	}

	else if (hor[idx].line == 1) {
		if (hor[idx].d == 0) {
			int next = pre + val;

			hor[idx].line = (next < 4) ? 1 : 2;
			hor[idx].loc = (next < 4) ? next : next - 1;

			if (next >= 7) {
				visit[1][pre] = (next == 8) ? 0 : visit[1][pre];
				hor[idx].loc = (next == 8) ? 0 : 20;
				hor[idx].state = (next == 8) ? -1 : 0;
				hor[idx].line = 0;
			}
		}

		else {
			int next = pre - val;

			hor[idx].line = (next > 4) ? 1 : 2;
			hor[idx].loc = (next > 4) ? next : 7 - next;

			if (next <= 1) {
				visit[1][pre] = (next == 0) ? 0 : visit[1][pre];
				hor[idx].loc = (next == 0) ? 0 : 20;
				hor[idx].state = (next == 0) ? -1 : 0;
				hor[idx].line = 0;
			}
		}
	}

	else {
		int next = pre + val;
		hor[idx].loc = next;

		if (next == 6) {
			hor[idx].line = 0;
			hor[idx].loc = 20;
		}

		if (next > 6) {
			visit[2][pre] = 0;
			hor[idx].loc = 0;
			hor[idx].state = -1;
		}
	}
}

void dfs(int cnt) {
	if (cnt == 10) {
		memset(visit, 0, sizeof(visit));
		int temp = 0;
		bool err = false;

		for (int i = 1; i <= 4; i++)
			hor[i].d = hor[i].line = hor[i].loc = hor[i].state = 0;

		for (int i = 0; i < cnt; i++) {
			int preline = hor[hores[i]].line, preloc = hor[hores[i]].loc;

			calNode(hores[i], num[i]);

			Hores cur = hor[hores[i]];

			if (cur.state == -1)
				continue;

			if (visit[cur.line][cur.loc]) {
				err = true;
				break;
			}

			visit[preline][preloc] = 0, visit[cur.line][cur.loc] = 1;
			temp += play[cur.line][cur.loc];
		}

		if (!err)
			ans = max(ans, temp);
		
		return;
	}

	for (int i = 1; i <= 4; i++) {
		hores[cnt] = i;
		dfs(cnt + 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 10; i++)
		cin >> num[i];

	for (int i = 1; i <= 20; i++)
		play[0][i] = i * 2;

	dfs(0);

	cout << ans << "\n";

	return 0;
}