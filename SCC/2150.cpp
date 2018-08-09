#include <iostream>
#include <ios>
#include <vector>
#include <stack>
#include <algorithm>

#define MAX 10001

using namespace std;

vector <int > dir[MAX], rdir[MAX], tmp;
vector <vector<int > > ans;
int cnt;
int visit[MAX] = { 0, };
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

	int V, E;
	int a, b;

	cin >> V >> E;

	while (E--) {
		cin >> a >> b;
		dir[a].push_back(b);
		rdir[b].push_back(a);
	}

	for (int i = 1; i <= V; i++)
		if (!visit[i])
			dfs(i);

	fill(visit, visit + V + 1, 0);
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
	sort(ans.begin(), ans.end());
	
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		for (int j : ans[i])
			cout << j << " ";
		cout << "-1" << endl;
	}
	return 0;
}