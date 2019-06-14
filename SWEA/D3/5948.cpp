#include <iostream>
#include <ios>

using namespace std;

int num[7], visit[7];
int ans[301];
int T;

void dfs(int idx, int cnt, int val) {
	if (cnt == 3) {
		ans[val]++;
		return;
	}

	for (int i = idx; i < 7; i++) {
		visit[i] = 1;
		dfs(i + 1, cnt+1, val + num[i]);
		visit[i] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int cnt = 0;

		for (int i = 0; i < 300; i++)
			ans[i] = 0;

		for (int i = 0; i < 7; i++)
			cin >> num[i];

		dfs(0, 0, 0);

		cout << "#" << t_case << " ";

		for (int i = 300; i > -1; i--) {
			if (ans[i] == 0)
				continue;

			cnt++;
			if (cnt == 5) {
				cout << i << "\n";
				break;
			}
		}

	}

	return 0;
}