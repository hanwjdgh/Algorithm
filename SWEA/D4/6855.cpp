#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>

using namespace std;

int T, ans, N, K;
int X[1000001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		vector <int > v;
		ans = 0;

		cin >> N >> K;

		for (int i = 0; i < N; i++)
			cin >> X[i];

		if (N <= K || N == 1)
			ans = 0;
		
		else {
			for (int i = 0; i < N - 1; i++) 
				v.push_back(X[i + 1] - X[i]);
			
			sort(v.begin(), v.end());

			for (int i = 0; i < N - K; i++)
				ans += v[i];
		}

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}