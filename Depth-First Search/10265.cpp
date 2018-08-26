#include <iostream>
#include <ios>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 1001

using namespace std;

vector <int > v[MAX];
int dp[MAX][MAX];
int visit[MAX];
int n, k;

int dfs(int cur) {
	int ret = 1;
	visit[cur] = 1;

	if (!visit[v[cur][0]])
		ret += dfs(v[cur][0]);

	return ret;
}

void re_dfs(int cur) {
	visit[cur] = 0;
	if (visit[v[cur][0]])
		re_dfs(v[cur][0]);
}

int find(int cur, int s_len) {
	if (cur > n)
		return 0;
	int &ret = dp[cur][s_len];

	if (ret != -1)
		return ret;

	ret = find(cur + 1, s_len);
	if (!visit[cur]) {
		int tmp = dfs(cur);
		if (s_len + tmp <= k)
			ret = max(ret, find(cur + 1, s_len + tmp) + tmp);
		re_dfs(cur);
	}
	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int num;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> num;
		v[i].push_back(num);
	}

	memset(dp, -1, sizeof(dp));
	cout << find(1, 0) << "\n";
	return 0;
}