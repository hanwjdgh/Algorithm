#include <iostream>
#include <ios>
#include <string>
#include <algorithm>

using namespace std;

string str1, str2;
int min_v = 51;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str1 >> str2;

	int temp = str2.length() - str1.length();

	for (int i = 0; i <= temp; i++) {
		int cnt = 0;

		for (int j = 0; j < str1.length(); j++)
			if (str1[j] != str2[j + i])
				cnt++;

		min_v = min(min_v, cnt);
	}

	cout << min_v << "\n";

	return 0;
}