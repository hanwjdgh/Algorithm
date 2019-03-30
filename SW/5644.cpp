#include <iostream>
#include <ios>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node {
	int y, x;
};

struct BC {
	int y, x, c, p;
};

Node node[2];
BC bc[9];
int A_move[101], B_move[101], near[2];
int dir[5][2] = { {0,0},{-1,0},{0,1},{1,0},{0,-1} };
int M, A, map[11][11], temp;

void dfs(int idx, int cnt) {
	if (cnt == 2) {
		int val = 0;
		if (near[0] == near[1])
			val += bc[near[0]].p;
		else
			val += (bc[near[0]].p + bc[near[1]].p);
		temp = max(temp, val);
		return;
	}

	bool find = false;
	for (int i = 1; i <= A; i++) {
		if (bc[i].c >= (abs(node[idx].y-bc[i].y)+abs(node[idx].x-bc[i].x))) {
			near[idx] = i;
			dfs(idx + 1, cnt + 1);
			near[idx] = 0;
			find = true;
		}
	}
	if (!find) {
		near[idx] = 0;
		dfs(idx + 1, cnt + 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		memset(map, 0, sizeof(map));
		int max_v = 0;
		node[0].x = node[0].y = 1;
		node[1].x = node[1].y = 10;

		cin >> M >> A;

		for (int i = 1; i <= M; i++)
			cin >> A_move[i];
		for (int i = 1; i <= M; i++)
			cin >> B_move[i];

		for (int i = 1; i <= A; i++)
			cin >> bc[i].x >> bc[i].y >> bc[i].c >> bc[i].p;

		for (int i = 0; i <= M; i++) {
			node[0].y += dir[A_move[i]][0], node[0].x += dir[A_move[i]][1];
			node[1].y += dir[B_move[i]][0], node[1].x += dir[B_move[i]][1];
			temp = 0;
			dfs(0, 0);
			max_v += temp;
		}

		cout << "#" << t_case << " " << max_v << "\n";
	}

	return 0;
}