#include <iostream>
#include <ios>
#include <cmath>

using namespace std;

int T, ans, a, b, c;
int x, y;

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a%b);
}

int extended_gcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	int x1, y1;
	int g = extended_gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

void solveDiophantine(int a, int b, int c, int &x, int &y) {
	int g = extended_gcd(a, b, x, y);

	c /= g;

	x = x * c; y = y * c;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int g;
		x = y = 0;

		cin >> a >> b >> c;

		solveDiophantine(a, b, c, x, y);

		g = gcd(a, b);

		int add = b / g;
		int num = 0;
		if (add < 0)
			num = (int)floor(1.0 * -x / add);
		else
			num = (int)ceil(1.0 * -x / add);

		x = x + b / g * num;
		y = y - a / g * num;

		cout << "#" << t_case << " " << x << " " << y << "\n";
	}

	return 0;
}