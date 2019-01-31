#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

priority_queue< int, vector<int>, less<int> > pq;
vector<pair<int, int> > p;
vector<int> bag;

int main() {
	int N, K;
	int a, b, c;
	long long sum = 0;

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		p.push_back(make_pair(a, b));
	}
	for (int i = 0; i < K; i++) {
		scanf("%d", &c);
		bag.push_back(c);
	}
	sort(p.begin(), p.end());
	sort(bag.begin(), bag.end());

	for (int i = 0, st = 0; i < K; i++) {
		if (st < N) {
			for (int j = st; j < N && p[j].first <= bag[i]; j++) {
				pq.push(p[j].second);
				st++;
				if (st == N)
					break;
			}
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	printf("%lld\n", sum);
	return 0;
}