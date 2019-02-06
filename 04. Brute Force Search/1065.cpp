#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N, x, y, z;
	int cnt = 99;

	cin >> N;

	if(N < 100)
		cout << N << "\n";
	else {
		if (N == 1000)
			N = 999;

		for (int i = 100; i <= N; i++) {
			x = i / 100;
			y = (i % 100) / 10;
			z = (i % 100) % 10;
			
			if (x - y == y - z)
				cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}