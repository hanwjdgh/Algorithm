#include <iostream>
#include <ios>
#include <queue>

using namespace std;

int T, K, num[1025], tmp;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		queue <int >q;
		int temp = 1;
		tmp = 1;

		cin >> K;

		for (int i = 0; i < K; i++)
			tmp *= 2;

		tmp -= 1;

		for (int i = 0; i < tmp; i++)
			cin >> num[i];

		q.push(tmp / 2);

		cout << "#" << t_case << " ";

		if (K == 1)
			temp = 0;
		else {
			for (int i = 0; i < K - 2; i++)
				temp *= 2;
		}

		int cnt = 0, chk = 2;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			cout << num[cur]<<" ";

			if (cur - temp < 0 || cur + temp >= tmp || temp == 0)
				continue;

			q.push(cur - temp);
			cnt++;
			q.push(cur + temp);
			cnt++;

			if (cnt == chk) {
				chk *= 2;
				cnt = 0;
				cout << "\n";
				temp /= 2;
			}
		}
		cout << "\n";
	}

	return 0;
}