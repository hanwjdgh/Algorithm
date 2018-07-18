#include <iostream>
#include <cstdio>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;

typedef tuple <int, int, int> t;
priority_queue< t, vector<t>, greater<t> > pq;
int root[1001];

int find(int n) {
	if (n == root[n])
		return n;
	return find(root[n]);
}

int main() {
	int N, M;
	int a, b, c;
	int ans=0;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		pq.push(make_tuple(c, a, b));
	}

	for (int i = 1; i <= N; i++)
		root[i] = i;

	while (!pq.empty()) {
		int x, y, w;
		t tmp = pq.top();
		pq.pop();
		w = get<0>(tmp), x = get<1>(tmp), y = get<2>(tmp);
		
		int from = find(x);
		int to = find(y);

		if (from == to)
			continue;
		root[to] = from;
		ans += w;
	}
	printf("%d", ans);
	return 0;
}