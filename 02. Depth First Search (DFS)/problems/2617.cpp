#include <iostream>
#include <ios>
#include <vector>

#define MAX 100

using namespace std;

vector <vector <int > > v, t;
int visit[MAX], chk[MAX];
int cnt;

void f_dfs(int cur) {
	visit[cur] = 1;
	cnt++;
	for (auto n : v[cur]) {
		if (!visit[n])
			f_dfs(n);
	}
}

void s_dfs(int cur) {
	visit[cur] = 1;
	cnt++;
	for (auto n : t[cur]) {
		if (!visit[n])
			s_dfs(n);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, a, b;
	int ans = 0;

	cin >> N >> M;

	v.resize(N + 1);
	t.resize(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		t[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		fill(visit, visit + MAX, 0);
		cnt = 0;
		f_dfs(i);
		if (cnt - 1 > N / 2)
			chk[i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		fill(visit, visit + MAX, 0);
		cnt = 0;
		s_dfs(i);
		if (cnt - 1 > N / 2)
			chk[i] = 1;
	}

	for (int i = 1; i <= N; i++) 
		if (chk[i])
			ans++;
	
	cout << ans << "\n";

	return 0;
}