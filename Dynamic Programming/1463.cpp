#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int > arr;

int main() {
	int N,num;

	cin >> N;
	
	arr.push_back(0);
	arr.push_back(0);

	for (int i = 2; i <= N; i++) {
		arr.push_back(arr[i - 1] + 1);
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1);
		if(i%2 == 0)
			arr[i] = min(arr[i], arr[i / 2] + 1);
	}

	cout << arr[N];
	return 0;
}