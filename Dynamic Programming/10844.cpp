#include <iostream>
#include <cstdio>
#include <vector>

#define value 1000000000
using namespace std;

vector <int > dp, tmp;

int main() {
	int N, hap = 0;

	cin >> N;

	for (int i = 0; i < 10; i++) {
		dp.push_back(1);
		tmp.push_back(1);
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[j] = tmp[1] % value;
			else if (j == 9)
				dp[j] = tmp[8] % value;
			else
				dp[j] = (tmp[j - 1] + tmp[j + 1]) % value;
		}
		for (int j = 0; j < 10; j++)
			tmp[j] = dp[j];
	}
	for (int i = 1; i < 10; i++)
		hap = (hap + dp[i]) % value;
	cout << hap%value;
	return 0;
}