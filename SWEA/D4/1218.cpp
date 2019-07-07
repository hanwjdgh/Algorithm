#include <iostream>
#include <ios>
#include <stack>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; t <= 10; t++) {
		int N, chk = 1;
		string str;
		stack <char > s;

		cin >> N >> str;

		if (N % 2 == 1)
			chk = 0;
		else {
			for (int i = 0; i < N; i++) {
				if (str[i] == '[' || str[i] == '{' || str[i] == '<' || str[i] == '(')
					s.push(str[i]);
				else {
					if (s.empty()) {
						chk = 0;
						break;
					}
					char temp = s.top();
					s.pop();
					if ((str[i] == ']' && temp != '[') || (str[i] == '}' && temp != '{') || (str[i] == '>'&& temp != '<') || (str[i] == ')'&& temp != '(')) {
						chk = 0;
						break;
					}
				}
			}
		}

		cout << "#" << t << " " << chk << "\n";
	}
	return 0;
}