#include <iostream>
#include <ios>

using namespace std;

int T, N, Q, L, R;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int box[1001] = { 0, };
		cin >> N >> Q;

		for (int i = 0; i < Q; i++) {
			cin >> L >> R;
			
			for (int j = L; j <= R; j++) {
				box[j] = i + 1;
			}
		}

		cout << "#" << t_case << " ";

		for (int i = 1; i <= N; i++)
			cout << box[i] << " ";

		cout << "\n";

	}

	return 0;
}