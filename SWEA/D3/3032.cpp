#include <iostream>
#include <ios>

using namespace std;

int T, A, B, ans;
int fx, fy, sx, sy;

int solve(int a, int b) {
	fx = 1, fy = 0, sx = 0, sy = 1;

	while (1) {
		if (a == 1)
			return 1;
		if (b == 1)
			return 2;
		if (a == 0 || b == 0) 
			return 0;

		fx -= a / b * sx;
		fy -= a / b * sy;
		a %= b;

		sx -= b / a * fx;
		sy -= b / a * fy;
		b %= a;
	
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		cin >> A >> B;

		cout << "#" << t_case << " ";

		ans = solve(A, B);

		if (ans == 1)
			cout << fx << " " << fy << "\n";
		else if (ans == 2)
			cout << sx << " " << sy << "\n";
		else
			cout << "-1" << "\n";
	}

	return 0;
}