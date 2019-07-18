#include <iostream>
#include <ios>

using namespace std;

int T, ans;
long long hap[1000001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int i = 1; i <= 1000000; i += 2)
		for (int j = 1; j <= 1000000 / i; j++)
			hap[i * j] += i;

	for (int i = 1; i <= 1000000; i++)
		hap[i] += hap[i - 1];

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;

		int L, R;

		cin >> L >> R;

		cout << "#" << t_case << " " << hap[R] - hap[L - 1] << "\n";
	}

	return 0;
}