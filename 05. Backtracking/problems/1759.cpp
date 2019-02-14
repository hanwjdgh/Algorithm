#include <iostream>
#include <ios>
#include <algorithm>
#include <string>

using namespace std;

int L, C;
char str[16];

void backtrack(int cnt, string prev, int ja, int mo) {
	if (prev.length() == L) {
		if (ja < 2 || mo < 1)
			return;
		cout << prev << endl;
	}

	for (int i = cnt; i < C; i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			backtrack(i + 1, prev + str[i], ja, mo + 1);
		else
			backtrack(i + 1, prev + str[i], ja + 1, mo);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> str[i];
	sort(str, str + C);

	backtrack(0,"",0,0);
	return 0;
}