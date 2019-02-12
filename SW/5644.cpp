#include <iostream>
#include <ios>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair <int, int > p;

vector <p > v;
vector <int > ans;
int dir[5][2] = { {0,0}, {0,-1},{1,0},{0,1},{-1,0} };
int dis[9], power[9];
int peo[2][2] = { {1,1}, {10,10} };
int M, A;

int find(int cnt, int idx) {
	if (cnt == 2) {
		int cnt = 0;
		if (ans[0] == ans[1])
			cnt += power[ans[0]];
		else
			cnt += (power[ans[0]] + power[ans[1]]);
		return cnt;
	}

	int val = 0;
	bool err = true;
	for (int i = 1; i <= A; i++) {
		if (dis[i] >= (abs(peo[idx][0] - v[i - 1].first) + abs(peo[idx][1] - v[i - 1].second))) {
			ans.push_back(i);
			val = max(val, find(cnt + 1, idx + 1));
			ans.pop_back();
			err = false;
		}
	}
	if (err) {
		ans.push_back(0);
		val = max(val, find(cnt + 1, idx + 1));
		ans.pop_back();
	}

	return val;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		fill(dis, dis + 9, 0);
		fill(power, power + 9, 0);
		string str;
		vector <int > A_move, B_move;
		int x, y, c, p, max_v = 0;
		peo[0][0] = peo[0][1] = 1;
		peo[1][0] = peo[1][1] = 10;

		A_move.push_back(0);
		B_move.push_back(0);
		v.clear();
		cin >> M >> A;

		cin.ignore();
		getline(cin, str);
		for (int i = 0; i < str.length(); i++)
			if (i % 2 == 0)
				A_move.push_back(str[i] - '0');

		getline(cin, str);
		for (int i = 0; i < str.length(); i++)
			if (i % 2 == 0)
				B_move.push_back(str[i] - '0');

		for (int i = 1; i <= A; i++) {
			cin >> x >> y >> c >> p;
			v.push_back({ x,y });
			dis[i] = c, power[i] = p;
		}

		for (int i = 0; i <= M; i++) {
			peo[0][0] += dir[A_move[i]][0], peo[0][1] += dir[A_move[i]][1];
			peo[1][0] += dir[B_move[i]][0], peo[1][1] += dir[B_move[i]][1];
			max_v += find(0, 0);
		}

		cout << "#" << t_case << " " << max_v << "\n";
	}

	return 0;

}