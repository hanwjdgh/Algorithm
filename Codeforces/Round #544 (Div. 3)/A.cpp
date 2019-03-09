#include <iostream>
#include <ios>
#include <string>

using namespace std;

int x, y;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str, str1;

	cin >> str >> str1;

	x = ((str[0] - '0') * 10 + (str[1] - '0')) * 60 + (str[3] - '0') * 10 + (str[4] - '0');
	y = ((str1[0] - '0') * 10 + (str1[1] - '0')) * 60 + (str1[3] - '0') * 10 + (str1[4] - '0');

	x += y;
	x /= 2;

	int f = x / 60, s = x % 60;

	if (f < 10)
		cout << "0" << f << ":";
	else
		cout << f << ":";

	if (s < 10)
		cout << "0" << s << "\n";
	else
		cout << s << "\n";

	return 0;
}