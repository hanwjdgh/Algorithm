#include <iostream>
#include <ios>
#include <queue>

#define MAX 1000001

using namespace std;

queue <long long > q;
long long visit[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, idx = 10;

	cin >> N;

	fill(visit, visit + MAX, -1);

	for (int i = 0; i < 10; i++) {
		visit[i] = i;
		q.push(i);
	}

	while (idx <= N && !q.empty()) {
		long long cur = q.front();
		q.pop();

		for (int i = 0; i < cur % 10; i++) {
			visit[idx++] = cur * 10 + i;
			q.push(cur * 10 + i);
		}
	}

	cout << visit[N] << "\n";

	return 0;
}