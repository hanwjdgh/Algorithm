#include <iostream>
#include <ios>

using namespace std;

int N, S, val[20];
int cnt, sum;

void dfs(int cur) {
	if (cur == N) 
		return;

	if (sum + val[cur] == S) 
		cnt++;

	dfs(cur + 1);

	sum += val[cur];
	dfs(cur + 1);

	sum -= val[cur];
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> val[i];
	dfs(0);
	cout << cnt;
	return 0;
}