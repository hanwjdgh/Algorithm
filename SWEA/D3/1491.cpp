#include <iostream>
#include <ios>

using namespace std;

int T;
long long ans, N, A, B;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		long long value = 0;
		cin >> N >> A >> B;

		ans = N*(A + B);
		for (int R = 1; R <= N; R++) {
			for (int C = 1; C*R <= N; C++) {
				if (R >= C)
					value = A*abs(R - C) + B*(N - R*C);
				if (ans > value)
					ans = value;
			}
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}