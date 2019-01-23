// This is an interactive problem.

#include <iostream>
#include <ios>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int m, n, L, R;
	char a;
	string str;

	while (true) {
		cin >> str;
		if ((str == "end") || (str == "mistake"))
			break;
		m = 0; n = 1;
		for (int i = 0; i <= 60; i++){
			cout << "? " << m << " " << n << endl;
			cin >> a;
			if (a == 'x')
				break;
			m = n;
			n = n * 2;
		}

		L = m + 1; R = min(n, 1000000000);
		while (L < R){
			int mid = (L + R) / 2;
			cout << "? " << m << " " << mid << endl;
			cin >> a;
			if (a == 'y') 
				L = mid + 1;
			else 
				R = mid;
		}

		cout << "! " << L << endl;
	}

	return 0;
}