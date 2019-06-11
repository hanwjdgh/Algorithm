#include <iostream>
#include <ios>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		string str;
		int ans = 0;
		int N, M;

		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			cin >> str;
			if (str.find("1") == string::npos || ans != 0)
				continue;

			int idx = str.find("1");

			for (int j = idx - 3; j < M - 55; j++) {
				int num[8], cnt = 0;

				for (int k = 0; k < 8; k++) {
					string temp = str.substr(j + k * 7, 7);

					if (temp == "0001101")
						num[k] = 0;
					else if (temp == "0011001")
						num[k] = 1;
					else if (temp == "0010011")
						num[k] = 2;
					else if (temp == "0111101")
						num[k] = 3;
					else if (temp == "0100011")
						num[k] = 4;
					else if (temp == "0110001")
						num[k] = 5;
					else if (temp == "0101111")
						num[k] = 6;
					else if (temp == "0111011")
						num[k] = 7;
					else if (temp == "0110111")
						num[k] = 8;
					else if (temp == "0001011")
						num[k] = 9;
					else {
						cnt = 1;
						break;
					}
				}
				if (cnt != 1) {
					int val = (num[0] + num[2] + num[4] + num[6]) * 3 + num[1] + num[3] + num[5] + num[7];
					if (val % 10 == 0) {
						ans = num[0] + num[1] + num[2] + num[3] + num[4] + num[5] + num[6] + num[7];
					}
					break;
				}

			}
		}
		cout << "#" << t << " " << ans << endl;
	}

	return 0;
}