#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int > arr;

int main() {
	int N, num, total;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	cin >> total;

	sort(arr.begin(), arr.end());
	int left = 0, right = arr[N - 1];
	long long max_v=0, val=0;

	while (left <= right) {
		int mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] > mid)
				sum += mid;
			else
				sum += arr[i];
		}
		if (sum > total)
			right = mid - 1;
		else {
			left = mid + 1;
			if (max_v < sum)
				val = mid;
		}
	}
	cout << val;
	return 0;
}