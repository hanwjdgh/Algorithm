#include <iostream>
#include <ios>
#include <algorithm>
#include <string>

using namespace std;

string cnt[10] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };
int T;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		string temp;
		int num[10] = { 0, };
		int len;

		cin >> temp >> len;

		cout << temp << "\n";

		for (int i = 0; i < len; i++) {
			cin >> temp;
			if (temp == "ZRO")
				num[0]++;
			else if (temp == "ONE")
				num[1]++;
			else if (temp == "TWO")
				num[2]++;
			else if (temp == "THR")
				num[3]++;
			else if (temp == "FOR")
				num[4]++;
			else if (temp == "FIV")
				num[5]++;
			else if (temp == "SIX")
				num[6]++;
			else if (temp == "SVN")
				num[7]++;
			else if (temp == "EGT")
				num[8]++;
			else
				num[9]++;
		}
		
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < num[i]; j++)
				cout << cnt[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}