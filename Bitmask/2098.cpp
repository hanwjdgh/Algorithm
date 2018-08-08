#include <iostream>
#include <ios>
#include <algorithm>

#define MAX 1000000000

using namespace std;

int arr[16][16], dp[16][1 << 16];
int N;

int TSP(int cur, int visit) {
	int &ret = dp[cur][visit];
	if (ret != 0)
		return ret;
	if (visit == (1 << N) - 1) {
		if (arr[cur][0] != 0)
			return arr[cur][0];
		return MAX;
	}

	ret = MAX;
	for (int i = 0; i < N; i++) {
		if (visit&(1 << i) || arr[cur][i] == 0)
			continue;
		ret = min(ret, TSP(i, visit | (1 << i)) + arr[cur][i]);
	}
	return ret;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	cout << TSP(0, 1);
	return 0;
}