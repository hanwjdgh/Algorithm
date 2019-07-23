#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int T, ans, N;
int num[500001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;
		
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> num[i];

		sort(num, num + N);
	
		int L = 0, R = num[N - 1];

		while (L <= R) {
			int mid = (L + R) / 2;
			int cnt = 0;

			for (int i = N-1; i > -1; i--) {
				if (num[i] >= mid)
					cnt++;
				else
					break;
			}
			
			if (cnt < mid)
				R = mid - 1;
			else
				L = mid + 1;

		}

		cout << "#" << t_case << " " << L - 1 << "\n";
	}

	return 0;
}