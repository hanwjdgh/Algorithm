#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int cup[4] = { 0,1,2,3 };
	int M, x, y;

	cin >> M;

	while (M--) {
		cin >> x >> y;
		swap(cup[x], cup[y]);
	}

	for (int i = 1; i < 4; i++) {
		if (cup[i] == 1)
			cout << i << "\n";
	}

	return 0;
}