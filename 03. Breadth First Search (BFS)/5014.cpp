#include <iostream>
#include <ios>
#include <queue>

#define MAX 1000000

using namespace std;

int visit[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	queue <int > q;
	int F, S, G, U, D;

	cin >> F >> S >> G >> U >> D;

	q.push(S);
	visit[S] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int dir[2] = { cur + U, cur - D };
		for (int i = 0; i < 2; i++) {
			if (dir[i] > F || dir[i] < 1 || visit[dir[i]])
				continue;
			q.push(dir[i]);
			visit[dir[i]] = visit[cur] + 1;
		}
	}

	if (visit[G])
		cout << visit[G] - 1 << "\n";
	else
		cout << "use the stairs" << "\n";

	return 0;
}