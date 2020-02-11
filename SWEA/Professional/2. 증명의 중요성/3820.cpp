#include <iostream>
#include <ios>
#include <algorithm>

#define MOD 1000000007

using namespace std;

// https://drops.dagstuhl.de/opus/volltexte/2016/6812/pdf/LIPIcs-ISAAC-2016-42.pdf

int T, n;

struct Node {
	long long a, b;
};

bool cmp(const Node& a, const Node& b) {
	return ((b.b * (a.a - 1)) > (a.b * (b.a - 1)));
}

Node node[200001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		long long ans = 1;

		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> node[i].a >> node[i].b;

		sort(node, node + n, cmp);
		
		for (int i = 0; i < n; i++)
			cout << node[i].a << " " << node[i].b << endl;

		for (int i = 0; i < n; i++)
			ans = ((node[i].a * ans) % MOD + node[i].b) % MOD;

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}