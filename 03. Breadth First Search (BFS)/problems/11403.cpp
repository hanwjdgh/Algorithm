#include <iostream>
#include <ios>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

vector <vector <int > > v;
int visit[MAX];


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, num;

	cin >> N;

	v.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num;
			if (num == 1)
				v[i].push_back(j);
		}
	}

	for (int i = 1; i <= N; i++) {
		fill(visit, visit + MAX, 0);
		queue <int > q;

		q.push(i);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (auto n : v[cur]) {
				if (!visit[n]) {
					visit[n] = 1;
					q.push(n);
				}
			}
		}

		for (int j = 1; j <= N; j++)
			cout << visit[j] << " ";
		cout << "\n";
	}

	return 0;
}