#include <iostream>
#include <ios>

using namespace std;

int T, ans, X;
int tnum[10], fnum[10], tlist[110];
int two, five, cnt;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int i = 0, two = five = 1; i <= 9; i++, two *= 2, five *= 5) {
		tnum[i] = two;
		fnum[i] = five;
	}

	for (int i = 0; i <= 9; i++) {
		int s, e;

		if (i < 3)
			s = 0, e = i + 1;
		else {
			s = i - 3, e = i + 1;
			if (i == 9)
				e = 9;
		}

		for (int j = s; j <= e; j++) 
			tlist[cnt++] = fnum[i] * tnum[j];
	}

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;

		cin >> X;

		for (int i = 0; i < cnt; i++) {
			if (tlist[i] > X)
				break;
			ans++;
		}

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}