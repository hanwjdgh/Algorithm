#include <iostream>
#include <ios>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

vector <int > v[MAX];
int visit[MAX] = { 0, };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, m;
	int x, y, a, b;
	int cnt = 0;

	cin >> n >> x >> y >> m;
	while (m--) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	queue <int > q;
	q.push(x);
	visit[x] = 1;
	int chk = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		if (cur == y) {
			chk = 1;
			break;
		}
		
		for (int next : v[cur]) {
			if (!visit[next]) {
				visit[next] = visit[cur]+1;
				q.push(next);
			}
		}
	}
	if (chk == 1)
		cout << visit[y] - 1;
	else
		cout << "-1";
	return 0;
}