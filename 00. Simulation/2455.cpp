#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int max_v, cur;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int a, b;

	for (int i = 0; i < 4; i++) {
		cin >> a >> b;
		cur -= a;
		cur += b;
		max_v = max(cur, max_v);
	}

	cout << max_v << "\n";
	return 0;
}