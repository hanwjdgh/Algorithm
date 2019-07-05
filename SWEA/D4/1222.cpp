#include <iostream>
#include <ios>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	stack <char > s;

	for (int t = 1; t <= 10; t++) {
		int N, ans = 0;
		string str;

		cin >> N >> str;
		
		for (int i = 0; i < N; i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				ans += (str[i] - '0');
			}
		}

		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}