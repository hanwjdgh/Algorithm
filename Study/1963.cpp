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

bool check(int cur, int next) {
	string a = to_string(cur), b = to_string(next);
	int chk = 0;

	for (int i = 0; i < 4; i++) 
		if (a[i] != b[i])
			chk++;
	
	if (chk == 1)
		return true;
	else
		return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

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

	cin >> T;
	while (T--) {
		fill(visit, visit + MAX, 0);
		int a, b;

		queue <p >q;

		cin >> a >> b;
		
		q.push({a,0});
		visit[a] = 1;

		while (!q.empty()) {
			int cur = q.front().first, cnt = q.front().second;
			q.pop();
			if (cur == b) {
				cout << cnt << "\n";
				break;
			}

			for (int next : v) {
				if (!visit[next] && check(cur, next)) {
					visit[next] = 1;
					q.push({ next,cnt+1 });
				}
			}
			cnt++;
		}

	}
	return 0;
}