#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int n, k, cnt;
int chk[101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int num;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> num;
		chk[num%k]++;
	}

	cnt = chk[0] / 2;

	for (int i = 1; i <= k/2; i++) {
		int tmp = k - i;
		if (i != tmp)
			cnt += min(chk[i], chk[tmp]);
		else
			cnt += chk[i]/2;
	}
	
	cout << cnt * 2 << "\n";

	return 0;
}