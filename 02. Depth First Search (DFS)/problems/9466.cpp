#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

int visit[MAX], stdt[MAX];
int check[MAX], cnt;

void dfs(int cur) {
	int next = stdt[cur];

	visit[cur] = 1;

	if (!visit[next])
		dfs(next);
	else {
		if (!check[next]) {
			for (int pre = next; pre != cur; pre = stdt[pre])
				cnt++;
			cnt++;
		}
	}

	check[cur] = 1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T, N;

	cin >> T;

	while (T--) {
		cin >> N;

		fill(visit, visit + MAX, 0);
		fill(stdt, stdt + MAX, 0);
		fill(check, check + MAX, 0);
		cnt = 0;

		for (int i = 0; i < N; i++)
			cin >> stdt[i + 1];

		for (int i = 1; i <= N; i++) {
			if (!visit[i])
				dfs(i);
		}

		cout << N - cnt << endl;
	}
	return 0;
}