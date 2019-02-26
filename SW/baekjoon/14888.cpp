#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

vector <int > v;

int N, op[4];
int max_v = -1e10, min_v = 1e10;

void find(int cnt, int val) {
	if (cnt == N) {
		max_v = max(max_v, val);
		min_v = min(min_v, val);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (!op[i])
			continue;
		op[i]--;
		if (i == 0)
			find(cnt + 1, val + v[cnt]);
		else if (i == 1)
			find(cnt + 1, val - v[cnt]);
		else if (i == 2)
			find(cnt + 1, val * v[cnt]);
		else
			find(cnt + 1, val / v[cnt]);
		op[i]++;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int num;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < 4; i++)
		cin >> op[i];

	find(1, v[0]);

	cout << max_v << "\n";
	cout << min_v << "\n";

	return 0;
}