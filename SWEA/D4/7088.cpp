#include <iostream>
#include <ios>
#include <cstring>

using namespace std;

struct Node {
	int L, R;
};

Node node[100001];
int T, N, Q, num;
int cnt[4][100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		memset(cnt, 0, sizeof(cnt));

		cin >> N >> Q;

		for (int i = 1; i <= N; i++) {
			cin >> num;

			for (int j = 1; j <= 3; j++) {
				if (j == num)
					cnt[j][i] = cnt[j][i - 1] + 1;
				else
					cnt[j][i] = cnt[j][i - 1];
			}
		}

		for (int i = 0; i < Q; i++)
			cin >> node[i].L >> node[i].R;

		cout << "#" << t_case << "\n";

		for (int i = 0; i < Q; i++) {
			for (int j = 1; j <= 3; j++)
				cout << cnt[j][node[i].R] - cnt[j][node[i].L - 1] << " ";
			cout << "\n";
		}
	}

	return 0;
}