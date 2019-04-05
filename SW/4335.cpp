#include <iostream>

using namespace std;

struct Box {
	int r, c, h;
};

int dp[21][1 << 20][3];
Box box[21];
int N, ans;

void dfs(int cur, int s1, int s2, int val, int bit, int mode) {
	if (cur != -1) {
		if (dp[cur][bit][mode] >= val)
			return;
		dp[cur][bit][mode] = val;

		if (ans < val)
			ans = val;
	}

	for (int i = 0; i < N; i++) {
		if (bit & (1 << i))
			continue;
		int next = bit | (1 << i);
		if ((s1 >= box[i].r && s2 >= box[i].c) || (s1 >= box[i].c && s2 >= box[i].r)) 
			dfs(i, box[i].r, box[i].c, val + box[i].h, next, 0);
		
		if ((s1 >= box[i].c && s2 >= box[i].h) || (s1 >= box[i].h && s2 >= box[i].c)) 
			dfs(i, box[i].c, box[i].h, val + box[i].r, next, 1);
		
		if ((s1 >= box[i].h && s2 >= box[i].r) || (s1 >= box[i].r && s2 >= box[i].h)) 
			dfs(i, box[i].h, box[i].r, val + box[i].c, next, 2);
		
	}
}

int main() {
	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> box[i].r >> box[i].c >> box[i].h;

		dfs(-1, 10001, 10001, 0, 0, 0);

		cout << "#" << t_case << " " << ans << "\n";

		ans = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < (1 << N); j++)
				for (int k = 0; k < 3; k++)
					dp[i][j][k] = 0;
	}

	return 0;
}