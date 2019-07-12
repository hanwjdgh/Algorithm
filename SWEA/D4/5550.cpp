#include <iostream>
#include <ios>
#include <string>
#include <algorithm>

using namespace std;

int T, ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int arr[5] = { 0, };
		string str;
		ans = 0;

		cin >> str;

		bool err = false;
		for (int i = 0; i < str.length(); i++) {
			switch (str[i]){
			case 'c':
				arr[0]++;
				break;

			case 'r':
				arr[0]--, arr[1]++;
				if (arr[0] < 0)
					err = true;
				break;

			case 'o':
				arr[1]--, arr[2]++;
				if (arr[1] < 0)
					err = true;
				break;

			case 'a':
				arr[2]--, arr[3]++;
				if (arr[2] < 0)
					err = true;
				break;

			case 'k':
				arr[3]--;
				if (arr[3] < 0)
					err = true;
				break;

			default:
				break;
			}

			ans = max(ans, arr[0] + arr[1] + arr[2] + arr[3]);
		}

		if (arr[0] != 0 || arr[1] != 0 || arr[2] != 0 || arr[3] != 0)
			err = true;

		if (err) 
			ans = -1;

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}