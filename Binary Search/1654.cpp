#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long > arr;

int main() {
	int K, N, num;
	long long left = 1, right = 0;
	long long max_v = 0;

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	right = arr[K - 1];

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long val = 0;
		for (int i = 0; i < K; i++) {
			val += arr[i] / mid;
		}
		if (val >= N) {
			left = mid + 1;
			max_v = max(max_v, mid);
		}
		else
			right = mid - 1;
	}
	cout << max_v;
	return 0;
}