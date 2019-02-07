#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int x;

	while (cin >> x) {
		int n, num;
		vector <int > v;
		bool check = false;

		cin >> n;
		x *= 10000000;

		for (int i = 0; i < n; i++) {
			cin >> num;
			v.push_back(num);
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < n; i++) {
			int temp = x - v[i];

			if (binary_search(v.begin() + i + 1, v.end(), temp)) {
				check = true;
				cout << "yes" << " " << v[i] << " " << temp << "\n";
				break;
			}
		}
		if (!check)
			cout << "danger" << "\n";
	}

	return 0;
}