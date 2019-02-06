#include <iostream>
#include <ios>
#include <vector>

using namespace std;

vector <int > v;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 1000; i < 10000; i++) {
		int temp = i, sum = 0, dsum = 0, hsum = 0;
		
		while (temp > 0) {
			sum += temp % 10;
			temp /= 10;
		}
		
		temp = i;
		while (temp > 0) {
			dsum += temp % 12;
			temp /= 12;
		}

		if (sum != dsum)
			continue;

		temp = i;
		while (temp > 0) {
			hsum += temp % 16;
			temp /= 16;
		}

		if (sum != hsum)
			continue;

		v.push_back(i);
	}

	for (auto n : v)
		cout << n << "\n";

	return 0;
}