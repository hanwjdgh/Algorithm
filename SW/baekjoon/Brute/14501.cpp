#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair <int, int > p;

vector <p > v;
int N, max_v;

void find(int cnt, int hap) {
	if (cnt == N + 1) {
		max_v = max(max_v, hap);
		return;
	}

	if (cnt + v[cnt].first <= N + 1)
		find(cnt + v[cnt].first, hap + v[cnt].second);
	if (cnt + 1 <= N + 1)
		find(cnt + 1, hap);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int d, p;

	cin >> N;

	v.push_back({ 0,0 });
	for (int i = 0; i < N; i++) {
		cin >> d >> p;
		v.push_back({ d,p });
	}
	
	find(1, 0);

	cout << max_v << "\n";

	return 0;

}