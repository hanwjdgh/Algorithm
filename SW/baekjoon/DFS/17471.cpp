#include <iostream>
#include <ios>
#include <algorithm>
#include <queue>

using namespace std;

int N, adj[11][11], min_v = 1e9;
int pnum[11], visit[11], tvisit[11];
int fidx, sidx;

bool check(int num, int lim) {
	int cnt = 0, temp[11] = { 0, };
	queue <int > q;
	q.push(num);
	temp[num] = 1;

	while (!q.empty()) {
		int cur = q.front();
		cnt++;
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (!adj[cur][i] || tvisit[i] || temp[i])
				continue;
			q.push(i);
			temp[i] = 1;
		}
	}
	if (cnt == lim)
		return true;
	return false;
}

bool acheck(int num, int lim) {
	int cnt = 0, temp[11] = { 0, };
	queue <int > q;
	q.push(num);
	temp[num] = 1;

	while (!q.empty()) {
		int cur = q.front();
		cnt++;
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (!adj[cur][i] || visit[i] || temp[i])
				continue;
			q.push(i);
			temp[i] = 1;
		}
	}
	if (cnt == lim)
		return true;
	return false;
}

void find(int cnt, int lim) {
	if (cnt > N) {
		if (fidx == lim) {
			int sum1 = 0, sum2 = 0, fnum = 0, snum = 0;
			bool err = false;

			for (int i = 1; i <= N; i++) {
				if (visit[i]) {
					if (fnum == 0)
						fnum = i;
					sum1 += pnum[i];
				}
			}

			for (int i = 1; i <= N; i++) {
				if (tvisit[i]) {
					if (snum == 0)
						snum = i;
					sum2 += pnum[i];

				}
			}
			if (!check(fnum, lim) || !acheck(snum, N - lim))
				return;

			if (!err) 
				min_v = min(min_v, abs(sum1 - sum2));
		}
		return;
	}

	visit[cnt] = 1; fidx++;
	find(cnt + 1, lim);
	visit[cnt] = 0; fidx--;

	tvisit[cnt] = 1; sidx++;
	find(cnt + 1, lim);
	tvisit[cnt] = 0; sidx--;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> pnum[i];

	for (int i = 1; i <= N; i++) {
		int num, t;

		cin >> num;

		for (int j = 0; j < num; j++) {
			cin >> t;

			adj[i][t] = adj[t][i] = 1;
		}
	}


	for (int i = 1; i <= N / 2; i++) {
		find(1, i);
	}

	if (min_v == 1e9)
		cout << -1 << "\n";
	else
		cout << min_v << "\n";

	return 0;
}