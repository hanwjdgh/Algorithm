#include <iostream>
#include <ios>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector <long long > v;
	long long N, num;
	long long ans=0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size() / 2; i++)
		ans += (v[i] + v[v.size() - 1 - i]) * (v[i] + v[v.size() - 1 - i]);
	
	cout << ans << "\n";

	return 0;
}