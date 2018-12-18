#include <iostream>
#include <ios>
#include <queue>

#define MAX 100001

using namespace std;

queue <int > q;
int visit[MAX] = { 0, };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K, cnt = 0;

	cin >> N >> K;

	q.push(N);
	visit[N] = 1;

	while (!q.empty()) {
		int size = q.size();
		while (size > 0) {
			int x = q.front();
			q.pop();

			if (x == K) {
				cout << cnt;
				break;
			}
			int dir[3] = { x - 1, x + 1, x * 2 };
			for (int i = 0; i < 3; i++) {
				int temp = dir[i];
				if (temp<0 || temp > MAX - 1)
					continue;
				if (!visit[temp]) {
					visit[temp] = 1;
					q.push(temp);
				}
			}
			size--;
		}
		cnt++;
	}
	return 0;
}