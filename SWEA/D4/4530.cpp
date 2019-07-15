#include <iostream>
#include <ios>
#include <string>

using namespace std;

int T;
long long ans;
string A, B;

long long cal(string str, int chk) {
	long long ret = 0;

	for (long long i = str.length() - 1, j = 1; i >= chk; i--, j *= 9) {
		long long temp = str[i] - '0';
		if (temp > 3)
			temp--;

		ret += (temp*j);
	}

	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;
		int A_chk, B_chk;
		long long A_val, B_val;

		cin >> A >> B;

		A_chk = (A[0] == '-') ? 1 : 0;
		B_chk = (B[0] == '-') ? 1 : 0;

		A_val = cal(A, A_chk), B_val = cal(B, B_chk);

		if (A_chk && B_chk)
			ans = A_val - B_val;
		else if (A_chk && !B_chk)
			ans = A_val + B_val - 1;
		else
			ans = B_val - A_val;

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}