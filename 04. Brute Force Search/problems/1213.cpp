#include <iostream>
#include <ios>
#include <string>

using namespace std;

int alcnt[26];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	bool error = false, check = false;
	string str;
	char temp;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
		alcnt[str[i] - 'A']++;

	for (int i = 0; i < 26; i++) {
		if (alcnt[i] % 2 == 1) {
			if (check) {
				error = true;
				break;
			}
			check = true;
			temp = (i + 'A');
		}
	}

	if (error)
		cout << "I'm Sorry Hansoo" << "\n";

	else {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < alcnt[i] / 2; j++)
				cout << (char)(i + 'A');
		}

		if (check)
			cout << temp;

		for (int i = 25; i >= 0; i--)
			for (int j = 0; j < alcnt[i] / 2; j++)
				cout << (char)(i + 'A');
		cout << "\n";
	}

	return 0;
}