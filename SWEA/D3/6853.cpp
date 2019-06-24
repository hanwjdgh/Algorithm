#include <iostream>
#include <ios>

using namespace std;

int T, N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int fx, fy, sx, sy;
		int x, y;

		int ans[3] = { 0, };

		cin >> fx >> fy >> sx >> sy;
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> x >> y;

			if (fx < x && x < sx && fy < y && y < sy)
				ans[0]++;
			else if (x< fx || x > sx || y < fy || y > sy)
				ans[2]++;
			else
				ans[1]++;
		}

		cout << "#" << t_case << " " << ans[0] << " " << ans[1] << " " << ans[2] << "\n";

	}

	return 0;
}