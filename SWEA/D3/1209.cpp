#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; t <= 10; t++) {
		int N, max_v = 0;
		int arr[101][101];

		cin >> N;

		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cin >> arr[i][j];

		for (int i = 0; i < 100; i++) {
			int hap = 0;
			for (int j = 0; j < 100; j++)
				hap += arr[i][j];
			max_v = max(max_v, hap);
		}

		for (int j = 0; j < 100; j++) {
			int hap = 0;
			for (int i = 0; i < 100; i++)
				hap += arr[i][j];
			max_v = max(max_v, hap);
		}

		int hap = 0;
		for (int i = 0; i < 100; i++)
			hap += arr[i][i];
		max_v = max(max_v, hap);

		hap = 0;

		for (int i = 0; i < 100; i++)
			hap += arr[i][99 - i];
		max_v = max(max_v, hap);

		cout << "#" << t << " " << max_v << "\n";
	}

	return 0;
}