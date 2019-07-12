#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int T, N;
int visit[17];
double P[17][17], ans;

void find(int cnt, double val) {
	if (val * 100 <= ans)
		return;

	if (cnt == N) {
		val *= 100;
		ans = max(ans, val);

		return;
	}

	for (int i = 0; i < N; i++) {
		if (visit[i])
			continue;
		visit[i] = 1;
		find(cnt + 1, val * P[cnt][i]);
		visit[i] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0.0;

		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> P[i][j];
				P[i][j] /= 100;
			}
		}

		find(0, 1);

		cout << fixed;
		cout.precision(6);
		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}