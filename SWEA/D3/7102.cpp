#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int T, N, M;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int num[41] = { 0, };
		int max_v = 0;

		cin >> N >> M;

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				num[i + j]++;

		for (int i = 2; i <= N + M; i++)
			max_v = max(max_v, num[i]);

		cout << "#" << t_case << " ";

		for (int i = 2; i <= N + M; i++)
			if (num[i] == max_v)
				cout << i << " ";

		cout << "\n";
	}

	return 0;
}