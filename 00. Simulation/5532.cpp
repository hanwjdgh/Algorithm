#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int L, A, B, C, D;

	cin >> L >> A >> B >> C >> D;

	cout << L - max(((A % C == 0) ? A / C : A / C + 1),((B % D == 0) ? B / D : B / D + 1)) << "\n";

	return 0;
}