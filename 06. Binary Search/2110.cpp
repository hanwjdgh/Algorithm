#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int > arr;

int main() {
	int N, C, num;

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	int left = 1, right = arr[N-1]-arr[0];
	int ans;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		int temp = arr[0];
		for (int i = 1; i < N; i++) {
			if (arr[i] - temp >= mid) {
				cnt++;
				temp = arr[i];
			}
		}
		if (cnt >= C - 1) {
			ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << ans;
	return 0;
}