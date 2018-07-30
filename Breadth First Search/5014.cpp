#include <iostream>
#include <ios>
#include <queue>

#define MAX 1000000

using namespace std;

int visit[MAX] = { 0, };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int F, S, G, U, D;

	cin >> F >> S >> G >> U >> D;

	queue <int > q;
	q.push(S);
	visit[S] = 1;

	while (!q.empty()) {
		int c = q.front();
		q.pop();
		
		int d[2] = { c + U, c - D };
		for (int i = 0; i < 2; i++) {
			if (d[i]<1 || d[i]>F)
				continue;
			if (visit[d[i]] != 0)
				continue;
			visit[d[i]] = visit[c] + 1;
			q.push(d[i]);
		}
	}
	if (visit[G] == 0)
		cout << "use the stairs";
	else
		cout << visit[G] - 1;
	return 0;
}