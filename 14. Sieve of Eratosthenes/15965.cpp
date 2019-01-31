#include <iostream>
#include <ios>
#include <vector>

#define MAX 10000000

using namespace std;

int chk[MAX + 1];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int k;

	vector<int> prime;
	for (int i = 2; i <= MAX; ++i) {
		if (chk[i])
			continue;
		prime.push_back(i);
		for (int j = i * 2; j <= MAX; j += i) 
			chk[j] = 1;
	}
	cin >> k;
	cout << prime[k-1] << endl;
	return 0;
}