#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <int > v;
int cnt[501], tile;

int cut_tile(int w, int h, int a) {
	if (w == 0 || h == 0)
		return 0;
	for (int i = a; i >= 0; i--) {
		if (cnt[i] == 0)
			continue;
		if (pow(2, i) <= w && pow(2, i) <= h) {
			tile--;
			cnt[i]--;
			cut_tile(w - pow(2, i), pow(2, i), i);
			cut_tile(w, h - pow(2, i), i);
			break;
		}
	}
	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int N, M, num, ans = 0;
		v.clear();
		fill(cnt, cnt + 501, 0);

		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			cin >> num;
			cnt[num]++;
			v.push_back(num);
		}

		tile = N;
		sort(v.begin(), v.end());

		while (1) {
			cut_tile(M, M, 30);
			ans++;
			if (tile == 0)
				break;
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}