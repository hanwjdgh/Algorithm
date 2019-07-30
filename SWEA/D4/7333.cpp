#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int T, N, ans;
int weg[101];

int main() {
	cin.tie(NULL);

	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;

		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> weg[i];

		sort(weg, weg + N);

		int tmp = 0, idx = 0;

		for (int i = N - 1; i > -1; i--) {
			tmp = weg[i];
			ans++;

			while(idx<i){
				if (tmp >= 50)
					break;
				tmp += weg[i];
				idx++;
			}

			if (tmp < 50)
				ans--;
			if (idx == i)
				break;
		}

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}