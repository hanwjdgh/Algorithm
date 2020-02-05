#include <iostream>
#include <ios>

using namespace std;

int T, N, K, sum;
int wear_Level[200001];
int Si[200001];

bool check(int sum, int val) {

	int cur_idx = 0;

	for (int i = 0; i < K; i++) {
		if (sum > N - cur_idx)
			return false;

		int cnt = 0;

		while (cnt < Si[i]) {
			if (cur_idx >= N) 
				return false;
		
			if (wear_Level[cur_idx] > val) {
				cur_idx++;
				cnt = 0;
				continue;
			}
			cur_idx++;
			cnt++;
		}
		sum -= Si[i];
	}
	return true;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int L = 200001, R = -1;

		sum = 0;

		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			cin >> wear_Level[i];

			L = (L > wear_Level[i]) ? wear_Level[i] : L;
			R = (R < wear_Level[i]) ? wear_Level[i] : R;
		}

		for (int i = 0; i < K; i++) {
			cin >> Si[i];
			sum += Si[i];
		}

		while (L <= R) {
			int mid = (L + R) / 2;

			if (check(sum, mid))
				R = mid - 1;
			else
				L = mid + 1;

		}
		cout << "#" << t_case << " " << L << "\n";
	}

	return 0;
}