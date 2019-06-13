#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int T, p, q;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int fx, fy, sx, sy, tx, ty;
		int n = 0, sum = 0;

		cin >> p >> q;

		while (1) {
			if (n*n + n - 2 * p >= 0)
				break;
			n++;
		}
		n -= 1;

		fx = p - (n*(n+1)/2);
		fy = n + 2 - fx;

		n = 0;
		while (1) {
			if (n*n + n - 2 * q >= 0)
				break;
			n++;
		}
		n -= 1;

		sx = q - (n*(n + 1) / 2);
		sy = n + 2 - sx;

		tx = fx + sx, ty = fy + sy;
		
		ty -= 2;
		ty += tx;

		sum = tx + (ty*(ty+1)/2);

		cout << "#" << t_case << " " << sum << "\n";
	}

	return 0;
}