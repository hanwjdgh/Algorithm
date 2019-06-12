#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 1; i <= 10; i++) {
		vector <int > v;
		int N, num, ans = 0;

		v.push_back(0);
		v.push_back(0);
		cin >> N;
		for (int a = 0; a < N; a++) {
			cin >> num;
			v.push_back(num);
		}
		v.push_back(0);
		v.push_back(0);

		for (int a = 2; a < N + 2; a++) {
			int L = max(v[a - 2], v[a - 1]), R = max(v[a + 1], v[a + 2]);
			if (v[a] <= L || v[a] <= R)
				continue;
			ans += (v[a] - max(L, R));
		}

		cout << "#" <<i<<" "<< ans << "\n";
	}

	return 0;
}