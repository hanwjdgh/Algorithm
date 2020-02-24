#include <iostream>
#include <ios>

using namespace std;

int T, N;
long long ans;
int arr[100001];

void merge(int left, int mid, int right) {
	int l = left, r = mid + 1;
	int* buf = new int[right + 1]();
	int s = left;

	while (l <= mid && r <= right) {
		if (arr[l] <= arr[r]) 
			buf[s] = arr[l++];
		else {
			ans += (mid + 1 - l);
			buf[s] = arr[r++];
		}
		s++;
	}

	if (l > mid) {
		for (int i = r; i <= right; i++, s++)
			buf[s] = arr[i];
	}

	else {
		for (int i = l; i <= mid; i++, s++)
			buf[s] = arr[i];
	}

	for (int i = left; i <= right; i++)
		arr[i] = buf[i];

	delete[] buf;
}

void mergeDivide(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;

		mergeDivide(left, mid);
		mergeDivide(mid + 1, right);

		merge(left, mid, right);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;

		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		mergeDivide(0, N - 1);

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}