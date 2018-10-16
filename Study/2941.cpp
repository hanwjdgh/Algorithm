#include <iostream>
#include <ios>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	int a = 0, sum = 0;

	cin >> str;

	while (1) {
		if (a == str.length())
			break;
		if (str[a] == 'c') {
			if (str[a + 1] == '=' || str[a + 1] == '-') {
				++sum;
				a += 2;
				continue;
			}
		}

		else if (str[a] == 'd') {
			if (str[a + 1] == '-') {
				++sum;
				a += 2;
				continue;
			}
			else if (str[a + 1] == 'z'&&str[a + 2] == '=') {
				++sum;
				a += 3;
				continue;
			}
		}
		else if (str[a] == 'l' || str[a] == 'n') {
			if (str[a + 1] == 'j') {
				++sum;
				a += 2;
				continue;
			}
		}

		else if (str[a] == 's' || str[a] == 'z') {
			if (str[a + 1] == '=') {
				++sum;
				a += 2;
				continue;
			}
		}
		sum++;
		++a;
	}
	cout << sum << "\n";
	return 0;
}