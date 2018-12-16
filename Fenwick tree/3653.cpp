#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

long long sum(vector<long long> &tree, int i) {
	long long ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i&-i);
	}
	return ans;
}

void update(vector<long long> &tree, int i, long long diff) {
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i&-i);
	}
}

int main() {
	int t, num;
	int n, m;
	scanf("%d", &t);
	for (int test = 0; test < t; test++) {
		vector<int> find,idx(1000001,0);
		vector<int> nodes;

		scanf("%d %d", &n, &m);
		
		for (int i = 1; i <= (n + m); i++) {
			if (i <= m)
				nodes.push_back(0);
			else {
				nodes.push_back(1);
				idx[i-m] = i;
			}
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", &num);
			find.push_back(num);
		}
		vector<long long> tree(n + m + 1);
		for (int i = 1; i <= (n + m); i++)
			update(tree, i, nodes[i - 1]);

		for (int a = 0; a < m; a++) {
			
			int index = idx[find[a]];
			printf("%lld ", sum(tree,index)-1);
			update(tree, index, -1);
			idx[find[a]] = m - a;
			update(tree, m-a, 1);

		}
		printf("\n");
	}
	return 0;
}
