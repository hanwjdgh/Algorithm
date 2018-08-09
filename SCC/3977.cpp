#include <iostream>
#include <ios>
#include <vector>
#include <stack>
#include <algorithm>

#define MAX 100001

using namespace std;

vector <vector<int > > dir, rdir, ans;
vector <int > tmp;
int num[MAX] = { 0, }, cont[MAX] = { 0, };
int visit[MAX] = { 0, };
int cnt;
stack <int > s;

void dfs(int cur) {
	visit[cur] = 1;
	for (int next : dir[cur])
		if (!visit[next])
			dfs(next);
	s.push(cur);
}

void scc(int cur) {
	visit[cur] = 1;
	num[cur] = cnt;
	for (int next : rdir[cur]) {
		if (!visit[next]) {
			tmp.push_back(next);
			scc(next);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, N, M;
	int a, b;

	cin >> T;
	while (T--) {
		cin >> N >> M;
		fill(visit, visit + N + 1, 0);
		fill(num, num + N + 1, 0);
		fill(cont, cont + N + 1, 0);

		dir.resize(N + 1);
		rdir.resize(N + 1);

		cnt = 0;
		while (M--) {
			cin >> a >> b;
			dir[a].push_back(b);
			rdir[b].push_back(a);
		}

		for (int i = 0; i < N; i++)
			if (!visit[i])
				dfs(i);

		fill(visit, visit + N + 1, 0);
		while (!s.empty()) {
			int x = s.top();
			s.pop();
			tmp.clear();
			if (!visit[x]) {
				tmp.push_back(x);
				scc(x);
				sort(tmp.begin(), tmp.end());
				ans.push_back(tmp);
				cnt++;
			}
		}

		for (int i = 0; i < N; i++)
			for (int j : dir[i])
				if (num[i] != num[j])
					cont[num[j]]++;

		int chk = 0, idx = -1;
		for (int i = 0; i < cnt; i++) {
			if (cont[i] == 0) {
				chk++;
				idx = i;
			}
		}
		if (chk > 1)
			cout << "Confused" << endl;
		else {
			for (int num : ans[idx])
				cout << num << endl;
		}
		cout << endl;

		ans.clear();
		dir.clear();
		rdir.clear();
	}
	return 0;
}