#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, a, b;
	int cnt = 0;

	cin >> N >> a >> b;

	while (a != b) {
		a = (a / 2) + (a % 2);
		b = (b / 2) + (b % 2);
		cnt++;
	}

	cout << cnt << "\n";

	return 0;
}