#include <iostream>
#include <ios>
#include <cmath>

#define MAX 101

using namespace std;

int road[MAX][MAX];
int N, L;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int ans = 0, j;
	cin >> N >> L;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> road[i][j];

	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (j = 0; j < N - 1; j++) {
			if (road[i][j] == road[i][j + 1])
				cnt++;
			else if (road[i][j] + 1 == road[i][j + 1] && cnt >= L)
				cnt = 1;
			else if (road[i][j] - 1 == road[i][j + 1] && cnt >= 0)
				cnt = -L + 1;
			else
				break;
		}
		if (j == N - 1 && cnt >= 0)
			ans++;

		cnt = 1;
		for (j = 0; j < N - 1; j++) {
			if (road[j][i] == road[j + 1][i])
				cnt++;
			else if (road[j][i] + 1 == road[j + 1][i] && cnt >= L)
				cnt = 1;
			else if (road[j][i] - 1 == road[j + 1][i] && cnt >= 0)
				cnt = -L + 1;
			else
				break;
		}
		if (j == N - 1 && cnt >= 0)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}