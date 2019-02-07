#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector <int > v, t, ans;
	int N, H, num;

	cin >> N >> H;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (i % 2 == 0)
			v.push_back(num);
		else
			t.push_back(num);
	}

	sort(v.begin(), v.end());
	sort(t.begin(), t.end());

	for (int i = 1; i <= H; i++) {
		int val1 = v.size() - (lower_bound(v.begin(), v.end(), i) - v.begin());
		int val2 = t.size() - (upper_bound(t.begin(), t.end(), H - i) - t.begin());

		ans.push_back(val1 + val2);
	}

	sort(ans.begin(), ans.end());

	int cnt = 0;

	for (auto n : ans) {
		if (n == ans[0])
			cnt++;
		else
			break;
	}

	cout << ans[0] << " " << cnt << "\n";

	return 0;
}