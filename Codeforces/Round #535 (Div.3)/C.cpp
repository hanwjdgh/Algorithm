#include <iostream>
#include <ios>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, min_v = 0, idx = 0;
	string str;
	string color[6] = { "RGB","RBG","GRB","GBR","BRG","BGR" };

	cin >> n >> str;

	min_v = n;

	for (int i = 0; i < 6; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) 
			cnt += (str[j] != color[i][j % 3]);

		if (cnt < min_v) 
			min_v = cnt, idx = i;
	}

	cout << min_v << "\n";

	for (int i = 0; i < n; i++)
		cout << color[idx][i % 3];
	cout << "\n";

	return 0;
}