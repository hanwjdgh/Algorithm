#include <iostream>
#include <cstdio>
#include <vector>

#define value 10007
using namespace std;

vector <vector<int > >dp;

int main() {
	int N, K;
	vector <int> tmp;

	cin >> N >> K;

	tmp.push_back(1);
	dp.push_back(tmp);
	tmp.clear();

	tmp.push_back(1);
	tmp.push_back(1);
	dp.push_back(tmp);
	tmp.clear();

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				tmp.push_back(1);
			else {
				tmp.push_back((dp[i - 1][j - 1] + dp[i - 1][j]) % value);
			}
		}
		dp.push_back(tmp);
		tmp.clear();
	}
	cout << dp[N][K] % value;
	return 0;
}