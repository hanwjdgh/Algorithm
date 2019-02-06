#include <iostream>
#include <ios>
#include <vector>

using namespace std;

typedef pair <int, char > p;

vector <p > v;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int K, N, t, time = 0;
	char ans;

	cin >> K >> N;

	for (int i = 0; i < N; i++) {
		cin >> t >> ans;

		time += t;
		if (time >= 210)
			break;

		if (ans == 'T') {
			if (K == 8)
				K = 1;
			else
				K++;
		}

	}

	cout << K << "\n";

	return 0;
}