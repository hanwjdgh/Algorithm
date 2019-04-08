#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int T, N, K, rot, cy;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t = 1; t <= T; t++) {
		int num[29] = { 0, };
		int result[29] = { 0, }, cnt = 0;
		char input;

		cin >> N >> K;

		rot = cy = N / 4;

		for (int i = 0; i < N; i++) {
			cin >> input;
			if ('0' <= input && input <= '9')
				num[i] = input - '0';
			else
				num[i] = input - 'A' + 10;
		}

		while (rot--) {
			for (int i = N - 1; i > -1; i -= cy) {
				int temp = 0;
				for (int j = 0; j < cy; j++)
					temp += num[i - j] * pow(16, j);
				result[cnt++] = temp;
			}

			int t_val = num[N - 1];
			for (int i = N - 1; i > 0; i--)
				num[i] = num[i - 1];
			num[0] = t_val;
		}

		for (int i = 0; i < cnt - 1; i++) {
			for (int j = 0; j < cnt - i - 1; j++) {
				if (result[j] < result[j + 1]) {
					swap(result[j], result[j + 1]);
				}
			}
		}

		int chk = 0, t_num = 0;
		for (int i = 0; i < cnt; i++) {
			if (t_num == result[i])
				continue;
			t_num = result[i];
			chk++;
			if (chk == K)
				break;
		}

		cout << "#" << t << " " << t_num << "\n";
	}

	return 0;
}