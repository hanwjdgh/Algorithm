#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int > dp;

int main(){
	int n,answer=0;

	cin >> n;
	dp.push_back(1);
	dp.push_back(1);

	if (n == 1)
		answer = dp[n - 1];
	else {
		for (int i = 2; i<n + 1; i++) 
			dp.push_back((dp[i - 2]*2 + dp[i - 1]) % 10007);
		answer = dp[n];
	}
	cout << answer;
}