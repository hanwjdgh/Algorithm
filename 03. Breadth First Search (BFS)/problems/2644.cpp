#include <iostream>
#include <ios>
#include <queue>
#include <vector>

#define MAX 101

using namespace std;

typedef pair <int, int > p;

vector <vector <int > > v;
int visit[MAX];
bool check;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	queue <p > q;
	int n, s, t, m;
	int a, b;

	cin >> n >> s >> t >> m;

	v.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	q.push({ s,0 });
	visit[s] = 1;

	while (!q.empty()) {
		int cur = q.front().first, cnt = q.front().second;
		q.pop();

		if (cur == t) {
			cout << cnt << "\n";
			check = true;
			break;
		}

		for (auto next : v[cur]) {
			if (!visit[next]) {
				q.push({ next,cnt + 1 });
				visit[next] = 1;
			}
		}
	}

	if (!check)
		cout << "-1" << "\n";

	return 0;
}