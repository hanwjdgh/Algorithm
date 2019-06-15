#include <iostream>
#include <ios>

using namespace std;

int T, N, P, A, B;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int C[5001] = { 0, }, idx[501] = { 0, };

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> A >> B;
			
			for (int i = A; i <= B; i++) 
				C[i]++;

		}

		cin >> P;

		for (int i = 0; i < P; i++)
			cin >> idx[i];

		cout << "#" << t_case << " ";

		for (int i = 0; i < P; i++)
			cout << C[idx[i]] << " ";
		cout << "\n";

	}

	return 0;
}