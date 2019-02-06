#include <iostream>
#include <ios>
#include <queue>

#define MAX 100001

using namespace std;

typedef pair <int, int > p;

int visit[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	queue <p > q;

	cin >> N >> K;

	q.push({ N,0 });
	visit[N] = 1;

	while (!q.empty()) {
		int cur = q.front().first, cnt = q.front().second;
		q.pop();

		if (cur == K) {
			cout << cnt << "\n";
			break;
		}

		int dir[3] = { cur + 1, cur - 1, cur * 2 };

		for (int i = 0; i < 3; i++) {
			int next = dir[i];
			if (next<0 || next>MAX || visit[next])
				continue;
			q.push({ next,cnt + 1 });
			visit[next] = 1;
		}
	}

	return 0;
}