#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int visit[101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int price[3];
	int s, f, min_v = 101, max_v = 0;
	int ans = 0;

	cin >> price[0] >> price[1] >> price[2];

	price[1] *= 2;
	price[2] *= 3;

	for (int i = 0; i < 3; i++) {
		cin >> s >> f;
		min_v = min(min_v, s);
		max_v = max(max_v, f);

		for (int j = s; j < f; j++)
			visit[j]++;
	}

	for (int i = min_v; i < max_v; i++) 
		ans += price[visit[i] - 1];
	
	cout << ans << "\n";

	return 0;
}