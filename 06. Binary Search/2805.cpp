#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long > arr;

int main() {
	int N, M;
	long long num;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	
	long long left=0, right=arr[N-1];
	
	while (left<=right) {
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if(arr[i]>mid)
				sum += arr[i] - mid;
		}
		if (sum >= M)
			left = mid+1;
		else
			right = mid-1;
	}
	cout << left-1;
	return 0;
}