#include <iostream>
#include <ios>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int T;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		string str,temp="";
		int cnt = 0;

		cin >> str;
		
		for (int i = 0; i < str.length(); i++)
			temp += '0';

		while (str.compare(temp)) {
			int idx = 0;
			char tchr;

			for (int i = 0; i < str.length(); i++) {
				if (str[i] != temp[i]) {
					idx = i;
					tchr = str[i];
					break;
				}
			}
			for (int i = idx; i < temp.length(); i++)
				temp[i] = tchr;
			cnt++;
		}

		cout << "#" << t << " " << cnt << "\n";
	}

	return 0;
}