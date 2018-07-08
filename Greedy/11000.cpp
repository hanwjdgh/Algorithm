#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

vector <pair <int, int> > p;
priority_queue< int, vector<int>, greater<int> > pq;

int main() {
	int N;
	int a, b;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		p.push_back(make_pair(a, b));
	}
	sort(p.begin(),p.end());
	
	pq.push(p[0].second);
	for (int i = 1; i < N; i++) {
		if (p[i].first >= pq.top()) {
			pq.pop();
			pq.push(p[i].second);
		}
		else
			pq.push(p[i].second);
	}
	printf("%d\n", pq.size());
	return 0;
}