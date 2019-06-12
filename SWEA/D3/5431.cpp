#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, K, num;
		int check[101];
		fill(check, check + 101, 0);
		cin >> N >> K;

		for (int i = 0; i < K; i++) {
			cin >> num;
			check[num] = 1;
		}
		cout << "#" << t << " ";

		for (int i = 1; i <= N; i++) {
			if (check[i] == 1)
				continue;
			cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}