#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int dp[11] = { 0,1,2,4 };
	int n,a;


	for (int i = 4; i < 11; i++) 
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	
	cin >> n;
	while (n--) {
		cin >> a;
		cout << dp[a] << endl;
	}
	return 0;
}