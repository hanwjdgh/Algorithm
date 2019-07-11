#include <iostream>
#include <ios>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int T, N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int ans = 0, num;
		vector <int > v;

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> num;
			v.push_back(num);
		}

		sort(v.begin(), v.end(), greater<int>());

		int na = N % 3;
		int total = N - na;

		for (int i = 0; i < na; i++) 
			ans += v[total + i];

		for (int i = 0; i < total; i++) {
			if (i == (3 * ((i/3)+1) - 1)) 
				continue;
			ans += v[i];
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}