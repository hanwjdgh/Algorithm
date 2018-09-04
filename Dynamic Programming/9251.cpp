#include <iostream>
#include <ios>
#include <string>
#include <algorithm>

#define MAX 1002

using namespace std;

string str1, str2;
int table[MAX][MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int row, col;

	cin >> str1 >> str2;

	col = str1.length();
	row = str2.length();

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (str2[i - 1] == str1[j - 1])
				table[i][j] = table[i - 1][j - 1] + 1;
			else
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
		}
	}

	cout << table[row][col] << "\n";
	return 0;
}