#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, num;
		int up = 0, down = 0;
		vector <int > v;
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> num;
			v.push_back(num);
		}

		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i] <= v[i + 1]) 
				up = max(up, v[i + 1] - v[i]);
			else 
				down = max(down, v[i] - v[i + 1]);
		}

		cout << "#" << t << " " << up << " " << down << "\n";
	}

	return 0;
}