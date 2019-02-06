#include <iostream>
#include <ios>
#include <algorithm>

#define MAX 51

using namespace std;

char map[MAX][MAX];
int min_v, max_v = 1;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;

	cin >> N >> M;

	min_v = min(N, M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 2; i <= min_v; i++) {

		for (int a = 0; a <= N - i; a++) {
			for (int b = 0; b <= M - i; b++) {
				if ((map[a][b] == map[a + i - 1][b]) && (map[a][b] == map[a][b + i - 1]) && (map[a][b] == map[a + i - 1][b + i - 1]))
					max_v = max(max_v, i*i);
			}
		}
	}

	cout << max_v << "\n";

	return 0;
}