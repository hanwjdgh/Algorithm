#include <iostream>
#include <ios>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, cnt = 0, ans = 0;
	int temp = 0;

	cin >> N;

	temp = N;

	while (N > 0) {
		cnt++;
		N /= 10;
	}

	for (int i = 0; i < cnt-1; i++) 
		ans += 9 * pow(10, i) * (i + 1);

	ans += (temp + 1 - pow(10, cnt - 1))*cnt;

	cout << ans << "\n";

	return 0;
}