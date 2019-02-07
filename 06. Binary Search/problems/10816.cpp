#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector <int > v;
	int N, M, num;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;
		cout << (upper_bound(v.begin(), v.end(), num) - v.begin()) - (lower_bound(v.begin(), v.end(), num) - v.begin()) << " ";
	}
	
	return 0;
}