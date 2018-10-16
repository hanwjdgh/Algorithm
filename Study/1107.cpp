#include <iostream>
#include <ios>
#include <cmath>
#include <algorithm>

#define MAX 1000000

using namespace std;

int visit[10];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int chan, N, num;
	int min_v = 1e9;

	cin >> chan >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		visit[num] = 1;
	}

	min_v = min(min_v, abs(chan - 100));

	for (int i = 0; i <= MAX; i++) {
		int temp = i;
		int cnt = 0;

		while (1) {
			if (visit[temp % 10])
				break;
			else {
				temp /= 10;
				cnt++;
				if (temp == 0) {
					min_v = min(min_v, abs(chan - i) + cnt);
                    break;
				}
			}
		}
	}
	cout << min_v << "\n";
	return 0;
}