#include <iostream>
#include <ios>
#include <vector>

using namespace std;

vector <int > v;
int N, S, cnt;

void find(int n, int sum) {
	if (n == N)
		return;
	if (sum + v[n] == S)
		cnt++;

	find(n + 1, sum + v[n]);
	find(n + 1, sum);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int num;

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	find(0, 0);

	cout << cnt << "\n";

	return 0;
}