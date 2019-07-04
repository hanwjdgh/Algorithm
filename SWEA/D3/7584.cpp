#include <iostream>
#include <ios>
#include <string>

using namespace std;

int T;
long long K, a;
string str1 = "001", str2 = "011";

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		char ans = ' ';
		bool flag = false;

		cin >> K;

		K--;
		a = K % 4;
		K /= 4;

		while (!flag) {
			if (a < 3) {
				if (K % 2 == 0) {
					ans = str1[a];
					flag = true;
				}
				if (!flag) {
					ans = str2[a];
					flag = true;
				}
			}

			a = K % 4;
			K /= 4;
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}