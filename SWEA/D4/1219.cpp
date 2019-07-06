#include <iostream>
#include <ios>
#include <vector>

#define MAX 101	

using namespace std;

vector < vector <int > > v;
int visit[MAX];
int chk;

void dfs(int cur) {
	if (cur == 99) {
		chk = 1;
		return;
	}
	visit[cur] = 1;

	for (auto n : v[cur]) 
		if (!visit[n])
			dfs(n);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; t <= 10; t++) {
		int N, M;
		int a, b;

		cin >> N >> M;

		chk = 0;
		v.clear();
		v.resize(MAX + 1);
		fill(visit, visit + MAX, 0);

		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			v[a].push_back(b);
		}

		dfs(0);

		cout << "#" << t << " " << chk << "\n";
	}
	return 0;
}