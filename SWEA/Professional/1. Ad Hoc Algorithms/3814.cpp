#include <iostream>
#include <ios>

using namespace std;

int T, N, K;
int num_Arr[100001], temp[100001];

bool check(int val) {
	int cnt = 0;

	for (int i = 0; i < N; i++)
		temp[i] = num_Arr[i];

	for (int i = 0; i < N - 1; i++) {
		if (temp[i] + val < temp[i + 1]) {
			cnt += temp[i + 1] - (temp[i] + val);
			temp[i + 1] = temp[i] + val;
		}
	}

	for (int i = N - 1; i > 0; i--) {
		if (temp[i] + val < temp[i - 1]) {
			cnt += temp[i - 1] - (temp[i] + val);
			temp[i - 1] = temp[i] + val;
		}
	}

	return cnt <= K;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int min_v = 1e9, max_v = 0;

		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			cin >> num_Arr[i];

			min_v = (num_Arr[i] < min_v) ? num_Arr[i] : min_v;
			max_v = (num_Arr[i] > max_v) ? num_Arr[i] : max_v;
		}

		int L = 0, R = max_v - min_v;

		while (L <= R) {
			int mid = (L + R) / 2;

			if (check(mid))
				R = mid - 1;

			else
				L = mid + 1;
		}

		cout << "#" << t_case << " " << L << "\n";
	}

	return 0;
}