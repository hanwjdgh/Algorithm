#include <iostream>

using namespace std;

int dp[1001][9][9][9][9][9];
int arrivr_time[1001], L[1001];
int N, t_case, ans, ft[5];

bool dfs(int p_cnt, int c_cnt) {
	if (p_cnt == N)
		return true;

	int wt[5] = { 0, };
	for (int i = 0; i < c_cnt; i++)
		wt[i] = arrivr_time[p_cnt] > ft[i] ? 0 : ft[i] - arrivr_time[p_cnt];

	if (dp[p_cnt][wt[0]][wt[1]][wt[2]][wt[3]][wt[4]] == t_case * 5 + c_cnt)
		return false;

	dp[p_cnt][wt[0]][wt[1]][wt[2]][wt[3]][wt[4]] = t_case * 5 + c_cnt;

	for (int i = 0; i < c_cnt; ++i) {
		if (ft[i] - arrivr_time[p_cnt] + L[p_cnt] > 10)
			continue;

		int temp = ft[i];
		ft[i] = arrivr_time[p_cnt] > ft[i] ? arrivr_time[p_cnt] + L[p_cnt] : ft[i] + L[p_cnt];
		if (dfs(p_cnt + 1, c_cnt)) {
			ft[i] = temp;
			return true;
		}
		ft[i] = temp;
	}
	return false;
}

int main() {
	int T;

	cin >> T;

	for (t_case = 1; t_case <= T; t_case++) {
		ans = -1;

		cin >> N;

		for (int i = 0; i < N; ++i)
			cin >> arrivr_time[i] >> L[i];

		for (int i = 5; i <= 5; ++i) {
			cout << "CPU : " << i << endl;
			if (dfs(0, i)) {
				ans = i;
				break;
			}
		}

		cout << "#" << t_case << " " << ans << '\n';
	}
	return 0;
}