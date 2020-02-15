#include <iostream>
#include <ios>

using namespace std;

int T, N;

struct Node {
	long long b, n;
};

Node node[10];

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

bool check_coprime() {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (gcd(node[i].n, node[j].n) != 1)
				return false;
		}
	}
	return true;
}

long long ext_gcd(long long A, long long B, long long* X, long long* Y) {
	long long x2, y2, x1, y1, x, y, r2, r1, q, r;

	x2 = 1; y2 = 0;
	x1 = 0; y1 = 1;

	for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y) {
		q = r2 / r1;
		r = r2 % r1;
		x = x2 - (q * x1);
		y = y2 - (q * y1);
	}
	*X = x2; *Y = y2;

	return r2;
}


long long CRT_coprime() {
	long long ret = 0, M = 1;
	long long q, r, t, r1, r2, t1, t2;

	for (int i = 0; i < N; i++)
		M *= node[i].n;

	for (int i = 0; i < N; i++) {

		r1 = node[i].n, r2 = M / node[i].n;
		t1 = 0, t2 = 1;

		while (r2 > 0) {
			q = r1 / r2;
			r = r1 - q * r2;
			r1 = r2, r2 = r;

			t = t1 - q * t2;
			t1 = t2, t2 = t;
		}

		t1 = (t1 < 0) ? t1 + node[i].n : t1;

		ret += (node[i].b * M * t1) / node[i].n;

	}

	return ret % M;
}

long long CRT_Ncoprime() {
	long long a1 = node[0].b, m1 = node[0].n;

	for (int i = 1; i < N; i++) {
		long long a2 = node[i].b, m2 = node[i].n;

		long long g = gcd(m1, m2);

		long long p, q;

		ext_gcd(m1 / g, m2 / g, &p, &q);

		long long mod = m1 / g * m2;
		long long x = (a1 * (m2 / g) * q + a2 * (m1 / g) * p) % mod;

		a1 = x;
		if (a1 < 0)
			a1 += mod;
		m1 = mod;
	}

	return a1 % m1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {

		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> node[i].b >> node[i].n;

		if (check_coprime())
			cout << "#" << t_case << " " << CRT_coprime() << "\n";
		else
			cout << "#" << t_case << " " << CRT_Ncoprime() << "\n";
	}
	return 0;
}