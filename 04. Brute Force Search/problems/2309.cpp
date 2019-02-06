#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int sum, t_a, t_b;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int height;
	vector <int > v;

	for (int i = 0; i < 9; i++) {
		cin >> height;
		v.push_back(height);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < 9; i++)
		sum += v[i];

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++)
			if (sum - (v[i] + v[j]) == 100) {
				t_a = i;
				t_b = j;
				break;
			}
	}

	for (int i = 0; i < 9; i++) {
		if (i == t_a || i == t_b)
			continue;
		else
			cout << v[i] << "\n";
	}

	return 0;
}