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

		cin >> N;
		for (int a = 0; a < 100; a++) {
			cin >> num;
			v.push_back(num);
		}

		for (int a = 0; a < N; a++) {
			sort(v.begin(), v.end());
			v[99]--;
			v[0]++;
		}
		sort(v.begin(), v.end());
		cout << "#" << i << " " << v[99] - v[0] << "\n";
	}

	return 0;
}