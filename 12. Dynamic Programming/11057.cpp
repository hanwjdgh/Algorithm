#include <iostream>
#include <cstdio>
#include <vector>

#define value 10007
using namespace std;

vector <int > dp;

int main() {
	int N, hap = 0;

	cin >> N;

	for (int i = 0; i < 10; i++)
		dp.push_back(1);
	dp.push_back(0);

	for (int i = 2; i <= N; i++) {
		for (int j = 9; j >= 0; j--)
			dp[j] = (dp[j] + dp[j + 1]) % value;

	}
	for (int i = 0; i < 10; i++)
		hap = (hap + dp[i]) % value;
	cout << hap % value;
	return 0;
}