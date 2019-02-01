#include <iostream>
#include <ios>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair <long long, long long  > p;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector <ll > a, c;
	priority_queue <p, vector<p>, greater<p> > pq;

	ll n, m, num, t, d;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num;
		a.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		cin >> num;
		c.push_back(num);
		pq.push({ num, i });
	}

	for (int i = 0; i < m; i++) {
		long long cost = 0;

		cin >> t >> d;

		while (d > 0) {
			ll min_a = min(a[t - 1], d);
			a[t - 1] -= min_a, d -= min_a;

			cost += (min_a * c[t - 1]);

			if (!a[t - 1])
				while (pq.size() && !a[pq.top().second])
					pq.pop();

			if (!pq.size() && d) {
				cost = 0;
				break;
			}
			t = pq.top().second + 1;
		}

		cout << cost << "\n";
	}

	return 0;
}