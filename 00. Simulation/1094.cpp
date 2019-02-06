#include <iostream>
#include <ios>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int X, cnt = 0;
	vector <int > v;

	cin >> X;

	while (X > 0) {
		v.push_back(X % 2);
		X /= 2;
	}

	for (int i = 0; i < v.size(); i++) 
		if (v[i] == 1)
			cnt++;

	cout << cnt << "\n";

	return 0;
}