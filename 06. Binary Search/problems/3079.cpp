#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long > v;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	long long N, M, t;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	long long L = 1, R = v[v.size() - 1] * M;

	while (L<=R){
		long long mid = (L + R) / 2;
		long long cnt = 0;

		for (int i = 0; i < N; i++)
			cnt += mid / v[i];

		if (cnt >= M)
			R = mid - 1;
		else
			L = mid + 1;

	}


	cout << L << "\n";

	return 0;
}