#include <iostream>
#include <ios>
#include <cstdio>
#include <vector>

using namespace std;

int T, N, M;

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
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	scanf("%d", &T);

	for (int t_case = 1; t_case <= T; t_case++) {
		vector <long long > v, ans;

		scanf("%d %d", &N, &M);
		
		for (int i = 0; i < N; i++) {
			long long num;
			scanf("%lld", &num);
			v.push_back(num);
		}

		vector<long long> tree(N + 1);
		for (int i = 1; i <= N; i++)
			update(tree, i, v[i - 1]);

		for (int i = 0; i < M; i++) {
			int C, L, R;

			scanf("%d %d %d", &C, &L, &R);
			if (C == 1)
				update(tree, L, R);
			else
				ans.push_back((sum(tree, R) - sum(tree, L - 1)));
		}

		printf("#%d ", t_case);
		for (auto n : ans)
			printf("%lld ", n);

		printf("\n");

	}

	return 0;
}