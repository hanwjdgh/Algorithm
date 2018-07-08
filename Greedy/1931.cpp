#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <int, int> > p;

int main() {
	int N;
	int a, b;
	int cnt = 0, temp = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		p.push_back(make_pair(b, a));
	}
	sort(p.begin(),p.end());

	for (int i = 0; i < N; i++) {
		if (p[i].second >= temp) {
			cnt++;
			temp = p[i].first;
		}
	}
	printf("%d\n", cnt);
	return 0;
}