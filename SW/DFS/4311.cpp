#include <iostream>

using namespace std;

int visit[1000], made_num[1000];
int num[10], op[5];
int N, O, M, W, num_cnt, ans;

void dfs(int num) {
	if (num == W) {
		if (ans == 0 || ans > visit[num] + 1)
			ans = visit[num] + 1;
		return;
	}

	for (int i = 0; i < num_cnt; i++) {
		int next;
		for (int j = 1; j <= 4; j++) {
			if (!op[j])
				continue;
			if (j == 1)
				next = num + made_num[i];
			else if (j == 2)
				next = num - made_num[i];
			else if (j == 4 && made_num[i] != 0)
				next = num / made_num[i];
			else
				next = num * made_num[i];

			if (next < 0 || next >= 1000)
				continue;
			if (visit[next] == 0 || visit[next] > visit[num] + visit[made_num[i]] + 1) {
				if (visit[num] + visit[made_num[i]] + 2 > M)
					continue;
				visit[next] = visit[num] + visit[made_num[i]] + 1;
				dfs(next);
			}
		}
	}
}

void make_num() {
	if (num[0]) {
		visit[0] = 1;
		made_num[num_cnt++] = 0;
	}
	for (int i = 1; i < 1000; i++) {
		int cnt = 0, temp = i;
		bool err = false;
		while (temp > 0) {
			if (!num[temp % 10]) {
				err = true;
				break;
			}
			cnt++;
			temp /= 10;
		}
		if (!err) {
			visit[i] = cnt;
			made_num[num_cnt++] = i;
		}
	}
}

int main() {
	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int val;

		cin >> N >> O >> M;

		for (int i = 0; i < N; i++) {
			cin >> val;
			num[val] = 1;
		}

		for (int i = 0; i < O; i++) {
			cin >> val;
			op[val] = 1;
		}

		cin >> W;

		make_num();

		if (visit[W] != 0 && visit[W] <= M)
			cout << "#" << t_case << " " << visit[W] << "\n";
		else {
			for (int i = 0; i < num_cnt; i++)
				dfs(made_num[i]);

			if (visit[W] == 0)
				cout << "#" << t_case << " " << -1 << "\n";
			else
				cout << "#" << t_case << " " << ans << "\n";
		}

		num_cnt = ans = 0;

		for (int i = 0; i < 10; i++)
			num[i] = 0;
		for (int i = 0; i < 5; i++)
			op[i] = 0;
		for (int i = 0; i < 1000; i++)
			visit[i] = made_num[i] = 0;
	}

	return 0;
}