#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int T, N;
int A[200001];

int find_max(int S, int E) {
	if (S == E)
		return A[S];

	int ret = 0;

	int mid = (S + E) / 2;

	int L = -2e9, R = -2e9;
	int sum = 0;

	for (int i = mid; i >= S; i--) {
		sum += A[i];
		L = max(L, sum);
	}

	sum = 0;
	for (int i = mid + 1; i <= E; i++) {
		sum += A[i];
		R = max(R, sum);
	}

	ret = max(find_max(S, mid), find_max(mid + 1, E));

	return max(L + R, ret);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {

		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> A[i];

		cout << "#" << t_case << " " << find_max(0, N - 1) << "\n";
	}

	return 0;
}
