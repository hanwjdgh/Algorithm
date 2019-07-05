#include <iostream>
#include <ios>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; t <= 10; t++) {
		int N, ans = 1;
		cin >> N;
		
		char tree[201];

		for (int i = 1; i <= N; i++) {
			int a, b, c;
			char ch;

			cin >> a >> ch;
			cin.ignore();
			if ((N % 2 == 0 && (i < N / 2)) || (N % 2 == 1 && i <= (N - 1) / 2)) {
				cin >> b >> c;
				tree[i] = ch;
			}
			else if (N % 2 == 0 && i == N / 2) {
				cin >> b;
				tree[i] = ch;
			}
			else 
				tree[i] = ch;
			
		}
		for (int i = 1; i <= N / 2; i++) {
			if (tree[i] >= '0' && tree[i] <= '9') {
				ans = 0;
				break;
			}
		}

		for (int i = N / 2 + 1; i <= N; i++) {
			if (tree[i] < '0' || tree[i] > '9') {
				ans = 0;
				break;
			}
		}

		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}