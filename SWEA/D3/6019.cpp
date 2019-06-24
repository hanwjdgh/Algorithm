#include <iostream>
#include <ios>

using namespace std;

int T;
double  D, A, B, F;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {

		cin >> D >> A >> B >> F;

		cout << fixed;
		cout.precision(6);

		cout << "#" << t_case << " " << F * (D / (A + B)) << "\n";

	}

	return 0;
}