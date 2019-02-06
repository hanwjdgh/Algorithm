#include <iostream>
#include <ios>
#include <vector>
#include <string>
#include <queue>

#define MAX 10000

using namespace std;

typedef pair<int, int > p;

vector <int > v;
bool prime[MAX];
int visit[MAX];

bool check(int a, int b) {
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int f = a % 10, s = b % 10;

		if (f == s)
			cnt++;
		a /= 10;
		b /= 10;
	}


	if (cnt == 3)
		return true;
	else
		return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T, a, b;

	cin >> T;

	prime[1] = true;
	for (int i = 2; i < MAX; i++) {
		if (prime[i])
			continue;
		for (int j = i * 2; j < MAX; j += i) {
			if (prime[j])
				continue;
			prime[j] = true;
		}
	}
	for (int i = 1000; i < MAX; i++)
		if (!prime[i])
			v.push_back(i);

	for (int i = 0; i < T; i++) {
		int ans = 0;

		cin >> a >> b;

		fill(visit, visit + MAX, 0);
		queue <p > q;

		q.push({ a,0 });
		visit[a] = 1;

		while (!q.empty()) {
			int cur = q.front().first, cnt = q.front().second;
			q.pop();

			if (cur == b) {
				ans = cnt;
				break;
			}

			for (auto next : v) {
				if (!visit[next] && check(cur, next)) {
					q.push({ next,cnt + 1 });
					visit[next] = 1;
				}
			}
		}

		cout << ans << "\n";
	}

	return 0;
}