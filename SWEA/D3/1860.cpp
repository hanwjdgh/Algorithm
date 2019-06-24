#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int T, N ,M, K;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		bool err = false;
		int t, arv[11112] = { 0, };
		int max_v = -1, bung = 0;

		cin >> N >> M >> K;

		for (int i = 0; i < N; i++) {
			cin >> t;
			max_v = max(max_v, t);
			arv[t]++;
		}
		
		for (int i = 0; i <= max_v; i++) {
			if (i != 0 && i % M == 0)
				bung += K;

			bung -= arv[i];

			if (bung < 0) {
				err = true;
				break;
			}
		}

		cout << "#" << t_case << " ";

		if (!err)
			cout << "Possible" << "\n";
		else
			cout << "Impossible" << "\n";
	}

	return 0;
}