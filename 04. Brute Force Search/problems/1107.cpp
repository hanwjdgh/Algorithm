#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int err[10];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, num;
	int min_v = 0;
	
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;
		err[num] = 1;
	}

	min_v = abs(100 - N);

	for (int i = 0; i < 1000000; i++) {
		int temp = i, cnt = 0;

		while (1) {
			if (err[temp % 10])
				break;
			else {
				cnt++;
				temp /= 10;
				if (temp == 0) {
					min_v = min(min_v, abs(i - N) + cnt);
					break;
				}
			}
		}
	}

	cout << min_v << "\n";

	return 0;
}