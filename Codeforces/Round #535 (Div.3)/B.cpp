#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector <int > v;
	int n, num;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = n - 1; i > 0; i--) {
		if (v[i] == v[i - 1] || v[n - 1] % v[i] != 0) {
			cout << v[n - 1] << " " << v[i] << endl;
			break;
		}
	}

	return 0;
}