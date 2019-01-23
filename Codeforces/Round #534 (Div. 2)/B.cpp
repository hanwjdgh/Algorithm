#include <iostream>
#include <ios>
#include <string>
#include <stack>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	stack <char > s;
	string str;
	int chk = 0;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (s.empty() || s.top() != str[i])
			s.push(str[i]);
		else {
			s.pop();
			chk++;
		}
	}

	cout << ((chk % 2 == 1) ? "YES" : "NO") << "\n";

	return 0;
}