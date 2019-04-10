#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int number[12], op[4];
int N, max_v, min_v;

void dfs(int cur, int val) {
	if (cur == N) {
		max_v = max(max_v, val);
		min_v = min(min_v, val);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (!op[i])
			continue;
		--op[i];
		if (i == 0)
			dfs(cur+1, val + number[cur]);
		else if (i == 1) 
			dfs(cur + 1, val - number[cur]);
		else if (i == 2) 
			dfs(cur + 1, val * number[cur]);
		else
			dfs(cur + 1, val / number[cur]);
		++op[i];
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		max_v = -1e10, min_v = 1e10;

		cin >> N;

		for (int i = 0; i < 4; i++) 
			cin >> op[i];	
		
		for (int i = 0; i < N; i++)
			cin >> number[i];

		dfs(1, number[0]);

		cout << "#" << t_case << " " << max_v - min_v << "\n";
	}

	return 0;
}