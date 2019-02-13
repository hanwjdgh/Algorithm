#include <iostream>
#include <ios>
#include <cstring>

#define MAX 21

using namespace std;

int arr[MAX][MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int N, X, cnt = 0;
		int i, j;

		cin >> N >> X;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];

		for (i = 0; i < N; i++) {
			int chk = 1;
			for (j = 0; j < N - 1; j++) {
				if (arr[i][j] == arr[i][j + 1])
					chk++;
				else if (arr[i][j] + 1 == arr[i][j + 1] && chk >= X)
					chk = 1;
				else if (arr[i][j] - 1 == arr[i][j + 1] && chk >= 0)
					chk = -X + 1;
				else
					break;
			}
			if (j == N - 1 && chk >= 0)
				cnt++;

			chk = 1;
			for (j = 0; j < N - 1; j++) {
				if (arr[j][i] == arr[j + 1][i])
					chk++;
				else if (arr[j][i] + 1 == arr[j + 1][i] && chk >= X)
					chk = 1;
				else if (arr[j][i] - 1 == arr[j + 1][i] && chk >= 0)
					chk = -X + 1;
				else
					break;
			}
			if (j == N - 1 && chk >= 0)
				cnt++;
		}

		cout << "#" << t_case << " " << cnt << "\n";
	}

	return 0;

}