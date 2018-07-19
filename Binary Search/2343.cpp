#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int > arr;

int main() {
	int N, M, num;
	int left = 0, right = 0;
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
		left = max(left, num);
	}

	for (int i = 0; i < N; i++)
		right += arr[i];

	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0, sum = 0;
		for (int i = 0; i < N; i++) {
			if (sum + arr[i] > mid) {
				cnt++;
				sum = 0;
			}
			sum += arr[i];
		}
		if (sum != 0)
			cnt++;
		if (cnt <= M)
			right = mid - 1;
		else
			left = mid + 1;
	}
	cout << left;
	return 0;
}