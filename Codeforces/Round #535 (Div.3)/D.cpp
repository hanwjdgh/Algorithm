#include <iostream>
#include <ios>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, cnt = 0;
	string str, color = "RGB";

	cin >> n >> str;

	for (int i = 1; i < n; i++) {
		if (str[i] == str[i - 1]) {
			cnt++;
			for (int j = 0; j < 3; j++) 
				if ((color[j] != str[i - 1]) && (color[j] != str[i + 1]))
					str[i] = color[j];
		}
	}

	cout << cnt << "\n";
	cout << str << "\n";

	return 0;
}