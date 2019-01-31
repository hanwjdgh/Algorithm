#include <iostream>
#include <ios>
#include <vector>
#include <string>
#include <map>

#define MAX 1000001

using namespace std;

bool prime[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	prime[0] = prime[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (prime[i])
			continue;
		for (int j = i * i; j <= MAX; j += i) {
			if (prime[j])
				continue;
			prime[j] = true;
		}
	}
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (!prime[i]) {

			map <int, int > m;
			int temp = i;
			while (1) {
				int sum = 0;
				string str = to_string(temp);
				int len = str.length();

				for (int j = 0; j < len; j++)
					sum += (str[j] - '0') * (str[j] - '0');

				if (sum == 1) {
					cout << i << "\n";
					break;
				}

				if (m.find(sum) == m.end())
					m[sum]++;
				else
					break;

				temp = sum;
			}
		}
	}
	return 0;
}