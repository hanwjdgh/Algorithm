#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;

	cout << n << "\n";

	for (int i = 0; i < n; i++)
		cout << "1" << " ";
	cout << "\n";

	return 0;
}