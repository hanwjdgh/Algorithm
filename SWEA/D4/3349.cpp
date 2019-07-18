#include <iostream>
#include <ios>
#include <cmath>

using namespace std;

int T, ans;
int W, H, N, px, py;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;

		cin >> W >> H >> N;
		cin >> px >> py;

		for (int i = 0; i < N - 1; i++) {
			int cx, cy;

			cin >> cx >> cy;

			if ((px > cx&&py > cy) || (px < cx&&py < cy)) {
				int tmp = (abs(px - cx) < abs(py - cy)) ? abs(px - cx) : abs(py - cy);
				ans += tmp;
				ans += abs(px - cx) - tmp + abs(py - cy) - tmp;
			}
			else 
				ans += abs(px - cx)+ abs(py - cy);

			px = cx, py = cy;
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}