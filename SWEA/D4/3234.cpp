#include <iostream>
#include <ios>
using namespace std;

int T, ans, N, sum;
int two[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
int fac[10] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
int num[10], visit[10];

void find(int cnt, int L, int R) {
	if (cnt == N) {
		ans++;
		return;
	}

	if (L >= sum - L) {
		ans += two[N - cnt] * fac[N - cnt];
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visit[i])
			continue;

		visit[i] = 1;
		find(cnt + 1, L + num[i], R);

		if(L >= R+num[i])
			find(cnt + 1, L, R + num[i]);
		visit[i] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;

		sum = 0;

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> num[i];
			sum += num[i];
		}

		find(0, 0, 0);

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}