#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>

using namespace std;

vector <int > v;
int max_v;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, num;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) 
		max_v = max(max_v, (upper_bound(v.begin(), v.end(), v[i] + 5) - v.begin() - i));
	
	cout << max_v << "\n";

	return 0;
}