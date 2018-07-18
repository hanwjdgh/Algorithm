#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int > arr;

int main() {
	int N,num,ans=0;
	
	cin >> N;
	vector <pair<int, int> > dp(N,make_pair(0,0));

	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	dp[0].first = 1, dp[0].second = arr[0];

	for (int i = 1; i < N; i++) {
		int temp = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[j] < temp) {
				dp[i].first = max(dp[i].first,dp[j].first+1);
				dp[i].second = max(dp[i].second, dp[j].second + arr[i]);
			}
		}
		if (dp[i].first == 0 && dp[i].second == 0) {
			dp[i].first = 1;
			dp[i].second = arr[i];
		}
	}

	for (int i = 0; i < dp.size(); i++) 
		ans = max(ans, dp[i].second);
	cout << ans;
	return 0;
}